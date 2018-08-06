//
//  Event.m
//  PagerAssessment
//
//  Created by Piyush Chhabra on 8/4/18.
//  Copyright © 2018 Piyush Chhabra. All rights reserved.
//

#import "Event.h"

static NSString * const kEventKey = @"name";
static NSString * const kUserKey = @"avatar";
static NSString * const kStateKey = @"github";


@implementation Event

- (NSString*)description
{
    return [NSString stringWithFormat:@"<%@: %p> %@) \"%@\" \"%@\"",
            [self class], self, self.event, self.user, self.state];
}

-(void)encodeWithCoder:(NSCoder *)coder {
    
    [coder encodeObject:self.user forKey:kUserKey];
    [coder encodeObject:self.event forKey:kEventKey];
    [coder encodeObject:self.state forKey:kStateKey];
    
}

- (BOOL)requiresSecureCoding
{
    return YES;
}

- (id)initWithCoder:(NSCoder *)coder
{
    self = [super init];
    if (self) {
        self.state = [coder decodeObjectOfClass:[NSString class] forKey:kStateKey];
        self.event = [coder decodeObjectOfClass:[NSString class] forKey:kEventKey];
        self.user = [coder decodeObjectOfClass:[NSString class] forKey:kUserKey];
    }
    return self;
}

@end
