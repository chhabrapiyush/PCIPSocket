//
//  PCIPSocket.h
//  PagerAssessment
//
//  Created by Piyush Chhabra on 8/3/18.
//  Copyright © 2018 Piyush Chhabra. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PCIPSocket;

@protocol PCIPSocketDelegate <NSObject>

@optional
/*
 The websocket connected to its host.
 @param socket is the current socket object.
 */
-(void)websocketDidConnect:(nonnull PCIPSocket*)socket;

/**
 The websocket was disconnected from its host.
 @param socket is the current socket object.
 @param error  is return an error occured to trigger the disconnect.
 */
-(void)websocketDidDisconnect:(nonnull PCIPSocket*)socket error:(nullable NSError*)error;

/**
 The websocket got a text based message.
 @param socket is the current socket object.
 @param string is the text based data that has been returned.
 */
-(void)websocket:(nonnull PCIPSocket*)socket didReceiveMessage:(nonnull NSString*)string;

/**
 The websocket got a binary based message.
 @param socket is the current socket object.
 @param data   is the binary based data that has been returned.
 */
-(void)websocket:(nonnull PCIPSocket*)socket didReceiveData:(nullable NSData*)data;

@end

@interface PCIPSocket : NSObject

@property(nonatomic,weak, nullable)id<PCIPSocketDelegate>delegate;
@property(nonatomic, readonly, nonnull) NSURL *url;

/**
 constructor to create a new websocket.
 @param url       the host you want to connect to.
 @param protocols the websocket protocols you want to use (e.g. chat,superchat).
 @return a newly initalized websocket.
 */
- (nonnull instancetype)initWithURL:(nonnull NSURL *)url protocols:(nullable NSArray*)protocols;

/**
 connect to the host.
 */
- (void)connect;

/**
 disconnect to the host. This sends the close Connection opcode to terminate cleanly.
 */
- (void)disconnect;

/**
 write binary based data to the socket.
 @param data the binary data to write.
 */
- (void)writeData:(nonnull NSData*)data;

/**
 write text based data to the socket.
 @param string the string to write.
 */
- (void)writeString:(nonnull NSString*)string;

/**
 write ping to the socket.
 @param data the binary data to write (if desired).
 */
- (void)writePing:(nonnull NSData*)data;

/**
 Add a header to send along on the the HTTP connect.
 @param value the string to send
 @param key   the HTTP key name to send
 */
- (void)addHeader:(nonnull NSString*)value forKey:(nonnull NSString*)key;

/**
 returns if the socket is conneted or not.
 */
@property(nonatomic, assign, readonly)BOOL isConnected;



/**
 Allows connection to self signed or untrusted WebSocket connection. Useful for development.
 Default setting is No.
 */
@property(nonatomic, assign)BOOL selfSignedSSL;

/**
 Set your own custom queue.
 Default setting is dispatch_get_main_queue.
 */
@property(nonatomic, strong, nullable)dispatch_queue_t queue;

/**
 Block property to use on connect.
 */
@property(nonatomic, strong, nullable)void (^onConnect)(void);

/**
 Block property to use on disconnect.
 */
@property(nonatomic, strong, nullable)void (^onDisconnect)(NSError*_Nullable);

/**
 Block property to use on receiving data.
 */
@property(nonatomic, strong, nullable)void (^onData)(NSData*_Nullable);

/**
 Block property to use on receiving text.
 */
@property(nonatomic, strong, nullable)void (^onText)(NSString*_Nullable);

@end

