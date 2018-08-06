//
//  User.m
//  PagerAssessment
//
//  Created by Piyush Chhabra on 8/4/18.
//  Copyright © 2018 Piyush Chhabra. All rights reserved.
//

#import "User.h"

static NSString * const kNameKey = @"name";
static NSString * const kAvatarKey = @"avatar";
static NSString * const kGithubKey = @"github";
static NSString * const kRoleKey = @"role";
static NSString * const kGenderKey = @"gender";
static NSString * const kLanguagesKey = @"languages";
static NSString * const kTagsKey = @"tags";
static NSString * const kLocationKey = @"location";


@implementation User

- (NSString*)description
{
    return [NSString stringWithFormat:@"<%@: %p> (%@) \"%@\"",
            [self class], self, self.github, self.name];
}


- (void)encodeWithCoder:(NSCoder*)coder
{
    [coder encodeObject:self.name forKey:kNameKey];
    [coder encodeObject:self.avatar forKey:kAvatarKey];
    [coder encodeObject:self.github forKey:kGithubKey];
    [coder encodeInt64:self.role forKey:kRoleKey];
    [coder encodeObject:self.gender forKey:kGenderKey];
    [coder encodeObject:self.languages forKey:kLanguagesKey];
    [coder encodeObject:self.tags forKey:kTagsKey];
    [coder encodeObject:self.location forKey:kLocationKey];
    
}

- (BOOL)requiresSecureCoding
{
    return YES;
}

- (id)initWithCoder:(NSCoder*)coder
{
    self = [super init];
    if (self) {
       
        self.name = [coder decodeObjectOfClass:[NSString class] forKey:kNameKey];
         self.avatar = [coder decodeObjectOfClass:[NSString class] forKey:kAvatarKey];
        self.github = [coder decodeObjectOfClass:[NSString class] forKey:kGithubKey];
        self.role = [coder decodeInt64ForKey:kRoleKey];
        self.gender = [coder decodeObjectOfClass:[NSString class] forKey:kGenderKey];
        self.languages = [coder decodeObjectOfClass:[NSArray class] forKey:kLanguagesKey];
        self.tags = [coder decodeObjectOfClass:[NSArray class] forKey:kTagsKey];
       self.location = [coder decodeObjectOfClass:[NSString class] forKey:kLanguagesKey];
    }
    return self;
}

//- (NSString*)githubID
//{
//    return self.user.fullName;
//}


@end
