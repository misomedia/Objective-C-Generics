//
//  Generics+Concurrency.h
//  Generics
//
//  Created by Ryan Tsukamoto on 5/23/12.
//  Copyright (c) 2012 Miso Media. All rights reserved.
//

#import <Foundation/Foundation.h>

//!	Assuming referential transparency of the input function, does the same thing as map, but does it concurrently.
NSArray* concurrentMap(id(^function)(id x), NSArray* preimage);

NSArray* concurrentMapWithSelector(SEL selector, NSArray* preimage);
