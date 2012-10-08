//
//  NSArray+Generics.h
//  Generics
//
//  Created by Ryan Tsukamoto on 3/19/12.
//  Copyright (c) 2012 Miso Media. All rights reserved.
//

#import <Generics/Generics.h>

///*!	\category NSArray(Generics)
//	\abstract A category on NSArray to provide Haskelly functional programming functionality with respect to (parametrically polymorphic or very lucky) arrays.
//	Ad hoc polymorphism will behave in an ad hoc manner.
//*/
//@interface NSArray(Generics)
//
////map
//+(NSArray*)mapBlock:(id(^)(id x))block overArray:(NSArray*)array;	//!<	This is map for blocks.
//+(NSArray*)mapSelector:(SEL)selector overArray:(NSArray*)array;	//!<	This is map for selectors.
//
////filter
//+(NSArray*)filterBlock:(bool(^)(id x))block overArray:(NSArray*)array;	//!<	This is filter.
//
////fold
//+(id)foldlWithBlock:(id(^)(id lhs, id rhs))block zero:(id)zero overArray:(NSArray*)array;	//!<	This is foldl.
//+(id)foldrWithBlock:(id(^)(id lhs, id rhs))block zero:(id)zero overArray:(NSArray*)array;	//!<	This is foldr.
//+(id)foldl1WithBlock:(id(^)(id lhs, id rhs))block overArray:(NSArray*)array;	//!<	This is foldl1.
//+(id)foldr1WithBlock:(id(^)(id lhs, id rhs))block overArray:(NSArray*)array;	//!<	This is foldr1.
//
////!	reorder
///*!
//	These methods do not directly sort a list using a comparator to project.
//	Instead, they construct a dictionary whose keys are the image of the list under a projection function and whose values are list of objects from the original list with the same projection.
//	Then they sort the keys using a comparator ON THE PROJECTIONS (which can assume that the inputs are not equal).
//	Then they map to get a list of lists.
//	Then they flatten the list of lists to get the result.
//	A sorting function is used once on a list which is possibly smaller than the original list.
//*/
//-(NSArray*)arrayByReorderingWithProjectionBlock:(id(^)(id))projectionBlock comparisonSelector:(SEL)comparisonSelector;
//
////!	reorder
///*!
//	These methods do not directly sort a list using a comparator to project.
//	Instead, they construct a dictionary whose keys are the image of the list under a projection function and whose values are list of objects from the original list with the same projection.
//	Then they sort the keys using a comparator ON THE PROJECTIONS (which can assume that the inputs are not equal).
//	Then they map to get a list of lists.
//	Then they flatten the list of lists to get the result.
//	A sorting function is used once on a list which is possibly smaller than the original list.
//*/
//-(NSArray*)arrayByReorderingWithProjectionBlock:(id(^)(id))projectionBlock comparisonBlock:(NSComparisonResult(^)(id, id))comparisonBlock;
//
////!	reorder
///*!
//	These methods do not directly sort a list using a comparator to project.
//	Instead, they construct a dictionary whose keys are the image of the list under a projection function and whose values are list of objects from the original list with the same projection.
//	Then they sort the keys using a comparator ON THE PROJECTIONS (which can assume that the inputs are not equal).
//	Then they map to get a list of lists.
//	Then they flatten the list of lists to get the result.
//	A sorting function is used once on a list which is possibly smaller than the original list.
//*/
//-(NSArray*)arrayByReorderingWithProjectionSelector:(SEL)projectionSelector comparisonSelector:(SEL)comparisonSelector;
//
////!	reorder
///*!
//	These methods do not directly sort a list using a comparator to project.
//	Instead, they construct a dictionary whose keys are the image of the list under a projection function and whose values are list of objects from the original list with the same projection.
//	Then they sort the keys using a comparator ON THE PROJECTIONS (which can assume that the inputs are not equal).
//	Then they map to get a list of lists.
//	Then they flatten the list of lists to get the result.
//	A sorting function is used once on a list which is possibly smaller than the original list.
//*/
//-(NSArray*)arrayByReorderingWithProjectionSelector:(SEL)projectionSelector comparisonBlock:(NSComparisonResult(^)(id, id))comparisonBlock;
//
////!	reorder
///*!
//	These methods do not directly sort a list using a comparator to project.
//	Instead, they construct a dictionary whose keys are the image of the list under a projection function and whose values are list of objects from the original list with the same projection.
//	Then they sort the keys using a comparator ON THE PROJECTIONS (which can assume that the inputs are not equal).
//	Then they map to get a list of lists.
//	Then they flatten the list of lists to get the result.
//	A sorting function is used once on a list which is possibly smaller than the original list.
//*/
//-(NSArray*)arrayByReorderingInReverseWithProjectionBlock:(id(^)(id))projectionBlock comparisonSelector:(SEL)comparisonSelector;
//
////!	reorder
///*!
//	These methods do not directly sort a list using a comparator to project.
//	Instead, they construct a dictionary whose keys are the image of the list under a projection function and whose values are list of objects from the original list with the same projection.
//	Then they sort the keys using a comparator ON THE PROJECTIONS (which can assume that the inputs are not equal).
//	Then they map to get a list of lists.
//	Then they flatten the list of lists to get the result.
//	A sorting function is used once on a list which is possibly smaller than the original list.
//*/
//-(NSArray*)arrayByReorderingInReverseWithProjectionBlock:(id(^)(id))projectionBlock comparisonBlock:(NSComparisonResult(^)(id, id))comparisonBlock;
////!	reorder
///*!
//	These methods do not directly sort a list using a comparator to project.
//	Instead, they construct a dictionary whose keys are the image of the list under a projection function and whose values are list of objects from the original list with the same projection.
//	Then they sort the keys using a comparator ON THE PROJECTIONS (which can assume that the inputs are not equal).
//	Then they map to get a list of lists.
//	Then they flatten the list of lists to get the result.
//	A sorting function is used once on a list which is possibly smaller than the original list.
//*/
//
////!	reorder
///*!
//	These methods do not directly sort a list using a comparator to project.
//	Instead, they construct a dictionary whose keys are the image of the list under a projection function and whose values are list of objects from the original list with the same projection.
//	Then they sort the keys using a comparator ON THE PROJECTIONS (which can assume that the inputs are not equal).
//	Then they map to get a list of lists.
//	Then they flatten the list of lists to get the result.
//	A sorting function is used once on a list which is possibly smaller than the original list.
//*/
//-(NSArray*)arrayByReorderingInReverseWithProjectionSelector:(SEL)projectionSelector comparisonSelector:(SEL)comparisonSelector;
//
////!	reorder
///*!
//	These methods do not directly sort a list using a comparator to project.
//	Instead, they construct a dictionary whose keys are the image of the list under a projection function and whose values are list of objects from the original list with the same projection.
//	Then they sort the keys using a comparator ON THE PROJECTIONS (which can assume that the inputs are not equal).
//	Then they map to get a list of lists.
//	Then they flatten the list of lists to get the result.
//	A sorting function is used once on a list which is possibly smaller than the original list.
//*/
//-(NSArray*)arrayByReorderingInReverseWithProjectionSelector:(SEL)projectionSelector comparisonBlock:(NSComparisonResult(^)(id, id))comparisonBlock;
//
////array
//-(id)headObject;	//!<	This is headObject for arrays.
//-(NSArray*)tailObjects;	//!<	This is tailObjects for arrays.
//-(NSArray*)initObjects;	//!<	This is initObjects (not the Objective-C init) for arrays.
////last object already exists lol.
//
//-(NSArray*)reverseObjects;	//!<	This is reverseObjects for arrays.
//
////map
//-(NSArray*)imageUnderBlock:(id(^)(id x))block;		//!<	This is per-instance map, but due to retarded Objective-C naming conventions, it is named thus.
//-(NSArray*)imageUnderSelector:(SEL)selector;	//!<	This is also per-instance map, but using an Objective-C selector instead of a block.
//
////filter
//-(NSArray*)filtrateUnderBlock:(bool(^)(id x))block;	//!<	This is per-instance filter.
//
////fold
//-(id)valueByFoldingLeftWithBlock:(id(^)(id a, id b))block zero:(id)zero;	//!<	This is per-instance foldl
//-(id)valueByFoldingRightWithBlock:(id(^)(id a, id b))block zero:(id)zero;	//!<	This is per-instance foldr.
//-(id)valueByFoldingLeftWithBlock:(id(^)(id a, id b))block;	//!<	This is per-instance foldl1.
//-(id)valueByFoldingRightWithBlock:(id(^)(id a, id b))block;	//!<	This is per-instance foldr1.
//
//@end
