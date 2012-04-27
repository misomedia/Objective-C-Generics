//
//  NSDictionary+Generics.h
//  SMNStaff
//
//  Created by Ryan Tsukamoto on 3/20/12.
//  Copyright (c) 2012 Miso Media. All rights reserved.
//

#import <Foundation/Foundation.h>

//!	A category for generics involving associative arrays (NSDictionary*).
@interface NSDictionary(Generics)

+(NSDictionary*)dictionaryByApplyingBlock:(id(^)(id key))keyBlock toEachKeyAndBlock:(id(^)(id object))objectBlock toEachObjectInDictionary:(NSDictionary*)dictionary;	//!<	given a dictionary, returns a dictionary containing the image of the original keys under keyBlock for keys and the image of the objects under objectBlock for objects.
+(NSDictionary*)dictionaryByApplyingSelector:(SEL)keySelector toEachKeyAndSelector:(SEL)objectSelector toEachObjectInDictionary:(NSDictionary*)dictionary;	//!<	given a dictionary, returns a dictionary containing the image of the original keys under keySelector for keys and the image of the objects under objectSelector for objects.

-(NSDictionary*)resultOfApplyingToEachKeyTheBlock:(id(^)(id key))keyBlock andToEachObjectTheBlock:(id(^)(id object))objectBlock;	//!<	returns a dictionary containing the image of the original keys under keyBlock for keys and the image of the objects under objectBlock for objects.
-(NSDictionary*)resultOfApplyingToEachKeyTheSelector:(SEL)keySelector andToEachObjectTheSelector:(SEL)objectSelector;	//!<	returns a dictionary containing the image of the original keys under keySelector for keys and the image of the objects under objectSelector for objects.

@end
