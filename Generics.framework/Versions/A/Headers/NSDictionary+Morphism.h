//
//  NSDictionary+Morphism.h
//  SMNStaff
//
//  Created by Ryan Tsukamoto on 3/20/12.
//  Copyright (c) 2012 Miso Media. All rights reserved.
//

#import <Foundation/Foundation.h>

//!	\file	A way to treat dictionaries as morphisms between arrays.
/*!
	Specifically, given a morphism, we store the domain as the keys and the image of the domain as objects.
*/

//!	A function for mapping over the keys and the objects in a dictionary using blocks.
/*!
	return nil if shit fucks up.
*/
NSDictionary* transformMappingWithBlocks(id(^keyBlock)(id key), id(^objectBlock)(id object), NSDictionary* mapping);

//!	A function for mapping over the keys and the objects in a dictionary using blocks
/*!
	return nil if shit fucks up.
*/
NSDictionary* transformMappingWithSelectors(SEL keySelector, SEL objectSelector, NSDictionary* mapping);

//!	A category for treating a NSDictionary as a morphism.
@interface NSDictionary(Morphism)

@end
