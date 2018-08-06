//
//  Event.h
//  PagerAssessment
//
//  Created by Piyush Chhabra on 8/4/18.
//  Copyright © 2018 Piyush Chhabra. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Event : NSObject <NSCoding>

@property (nonatomic, copy) NSString* event;
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* state;

@end
