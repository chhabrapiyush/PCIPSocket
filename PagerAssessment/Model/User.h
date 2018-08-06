//
//  User.h
//  PagerAssessment
//
//  Created by Piyush Chhabra on 8/4/18.
//  Copyright © 2018 Piyush Chhabra. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface User : NSObject <NSCoding>


@property (nonatomic, copy) NSString* name;
@property (nonatomic, copy) NSString* avatar;
@property (nonatomic, copy) NSString* github;
@property (nonatomic) int64_t role;
@property (nonatomic, copy) NSString* gender;

@property (nonatomic, copy) NSArray<NSString *>* languages;
@property (nonatomic, copy) NSArray<NSString *>* tags;
@property (nonatomic, strong) NSString* location;


@end
