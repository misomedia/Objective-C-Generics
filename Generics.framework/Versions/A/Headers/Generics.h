//
//  Generics.h
//  SMNStaff
//
//  Created by Ryan Tsukamoto on 3/21/12.
//  Copyright (c) 2012 Miso Media. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import <Generics/NSArray+Generics.h>
//#import <Generics/NSDictionary+Generics.h>
//#import <Generics/NSDictionary+Morphism.h>
//#import <Generics/Generics+Unsafe.h>
//#import <Generics/Generics+Concurrency.h>

//!	\file Generics.h has Haskelly goodness for all!  All code examples come from Haskell's Prelude module.

//!	Returns the head object (first object).
/*!
	headObject takes an array and returns the first argument, returning nil if the array is empty or nil.
*/
id headObject(NSArray* array);

//!	Returns the tail objects.
/*!
	tailObjects takes an array and returns everything after the first argument, returning nil if the array is empty or nil and returning an empty array if the array is of length one.
*/
NSArray* tailObjects(NSArray* array);

//!	Returns the initial objects.
/*!
	initObjects takes an array and returns everything except for the last object, returning nil if the array is empty or nil and returning an empty array if the array is of length one. 
*/
NSArray* initObjects(NSArray* array);

//!	Returns the last object.
/*!
	lastObject takes an array and returns the last object.
*/
id lastObject(NSArray* array);

//!	Returns an array containing the objects in the given array in reverse.
NSArray* reverseObjects(NSArray* array);

//!	id function.
id(^id_function)(id);

//!	A generic map function.
/*!
	map takes, as arguments, a function (variably typed function of a single argument of variable type using blocks) and an preimage list (NSArray*).
	It returns an image list containing the images of the elements of the original list under the function.

	In Haskell:
	\code
	map :: (a -> b) -> [a] -> [b]
	map f []     = []
	map f (x:xs) = f x : map f xs
	\endcode
	\param	function	the functional argument as a variably typed function of a single argument of variable type using blocks.
	\param	preimage	the preimage as an NSArray*.
*/
NSArray* map(id(^function)(id x), NSArray* preimage);

//!	A generic-ish map function.
/*!
	mapWithSelector does the same thing as map, but with an Objective-C selector (to be used by the runtime) in place of a function.
	\param	selector	the functional argument as a selector.
	\param	preimage	the preimage as an NSArray*.
	If the function returns nil when applied to any element of the preimage, the whole thing will be nil.  Arrays do not like nil values, and we'd like to have a map which preserves length or blows up.  No in between...
*/
NSArray* mapWithSelector(SEL selector, NSArray* preimage);

//!	Matrix multiplication from the left using a row vector of functions, using cons instead of plus and function application as multiplication.
/*!
	mapTuples takes an n-tuple of functions (NSArray*) and a list of n-tuples (NSArray*) and performs matrix multiplication treating the functions tuple as a row vector
	
	\param	functionsTuple	the n-tuple of functions as an NSArray* of blocks.
	\param	tuples	the list of n-tuple arguments to the functions as an NSArray* of NSArray*s.
	If the selector returns nil when applied to any element of the preimage, the whole thing will be nil.  Arrays do not like nil values, and we'd like to have a map which preserves length or blows up.  No in between...
*/
NSArray* mapTuples(NSArray* functionsTuple, NSArray* tuples);

//!	Same as mapTuples but using a C array of selectors instead of an NSArray of blocks.
/*!
	\param	selectorsTuple	the n-tuple of functions as a C array of selectors.
	\param	tuples	the list of n-tuple arguments to the functions as an NSArray* of NSArray*s.
*/
NSArray* mapTuplesWithSelector(SEL* selectorsTuple, NSArray* tuples);

//!	A generic variation of map which takes nested dictionaries and applies a function to each object which is not a dictionary, applying itself to every object which is a dictionary, and returns the results in a dictionary with the original keys.
NSDictionary* mapThroughNestedDictionaries(id(^function)(id x), NSDictionary* preimage);

//!	A generic filter function.
/*!
	filter takes a predicate (bool typed function of a single argument of variable type using blocks) and a list (NSArray*).
	It returns the elements of the list, in order, which satisfy the predicate.

	In Haskell:
	\code
	filter :: (a -> Bool) -> [a] -> [a]
	filter p []                 = []
	filter p (x:xs) | p x       = x : filter p xs
					| otherwise = filter p xs
	\endcode
	\param	predicate	the predicate as a bool typed function of a single argument of variable type using blocks.
	\param	feed	the feed as an NSArray*.
*/
NSArray* filter(bool(^predicate)(id x), NSArray* feed);

//!	A generic foldl function.
/*!
	foldl takes, as arguments, a function (variably typed function of two arguments of variable type using blocks), a (metaphorically) zero value (id), and an list (NSArray*).
	If the list is empty, it returns the zero value.
	Otherwise, it applies foldl to the function, the result of applying the function to the zero value (on the left) and the head of the list (on the right), and the tail of the list.

	In Haskell:
	\code
	foldl            :: (a -> b -> a) -> a -> [b] -> a
	foldl f z []     =  z
	foldl f z (x:xs) =  foldl f (f z x) xs
	\endcode
	\param	function	the functional argument as a variably typed function of two arguments of variable type using blocks.
	\param	zero	the zero.
	\param	list	the list as an NSArray*.
*/
id foldl(id(^function)(id lhs, id rhs), id zero, NSArray* list);

//!	A generic foldr function.
/*!
	foldr takes, as arguments, a function (variably typed function of two arguments of variable type using blocks), a zero value (id), and a list (NSArray*).
	If the list is empty, it returns the zero value.
	Otherwise, it returns result of applying the function to the head of the list (on the left) and the result of applying foldr to the function, the zero value, and the tail of the list.

	In Haskell:
	\code
	foldr            :: (a -> b -> b) -> b -> [a] -> b
	foldr f z []     =  z
	foldr f z (x:xs) =  f x (foldr f z xs)
	\endcode
	\param	function	the functional argument as a variably typed function of two arguments of variable type using blocks.
	\param	zero	the zero.
	\param	list	the list as an NSArray*.
*/
id foldr(id(^function)(id lhs, id rhs), id zero, NSArray* list);

//!	A generic foldl1 function.
/*!
	foldl1 takes, as arguments, a function (variably typed function of two arguments of variable type using blocks), and a nonempty list (NSArray*).
	It returns the result of applying foldl to the function, the head of the list, and the tail of the list.

	In Haskell:
	\code
	foldl1           :: (a -> a -> a) -> [a] -> a
	foldl1 f (x:xs)  =  foldl f x xs
	foldl1 _ []      =  error "Prelude.foldl1: empty list"
	\endcode
	\param	function	the functional argument as a variably typed function of two arguments of variable type using blocks.
	\param	nonemptyList	the nonempty list as an NSArray*.
*/
id foldl1(id(^function)(id lhs, id rhs), NSArray* nonemptyList);

//!	A generic foldr1 function.
/*!
	foldr1 takes, as arguments, a function (variably typed function of two arguments of variable type using blocks), and a nonempty list (NSArray*).
	If the nonempty list is of length one, it returns the single item in the list.
	Otherwise it returns the result of applying the function to the head of the list and the result of applying foldr1 to the function and the tail of the list.

	In Haskell:
	\code
	foldr1           :: (a -> a -> a) -> [a] -> a
	foldr1 f [x]     =  x
	foldr1 f (x:xs)  =  f x (foldr1 f xs)
	foldr1 _ []      =  error "Prelude.foldr1: empty list"
	\endcode
	\param	function	the functional argument as a variably typed function of two arguments of variable type using blocks.
	\param	nonemptyList	the nonempty list as an NSArray*.
*/
id foldr1(id(^function)(id lhs, id rhs), NSArray* nonemptyList);

//!	A generic maximum function.
/*!
	maximum takes, as arguments, a nonempty list and a lessThan block.  It returns the greatest item in the list.
	
	In Haskell:
	\code
	maximum :: (Ord a) => [a] -> a
	maximum []       =  error "Prelude.maximum: empty list"
	maximum xs       =  foldl1 max xs
	\endcode
	\param	lessThanFunction	a function (as a block) used to compare items in the list.
	\param	nonemptyList	the nonempty list as an NSArray*.
*/
id maximum(NSComparisonResult(^lessThanFunction)(id lhs, id rhs), NSArray* nonemptyList);

//!	A generic minimum function.
/*!
	minimum takes, as arguments, a nonempty list and a lessThan block.  It returns the least item in the list.
	
	In Haskell:
	\code
	minimum :: (Ord a) => [a] -> a
	minimum []       =  error "Prelude.minimum: empty list"
	minimum xs       =  foldl1 min xs
	\endcode
	\param	lessThanFunction	a function (as a block) used to compare items in the list.
	\param	nonemptyList	the nonempty list as an NSArray*.
*/
id minimum(NSComparisonResult(^lessThanFunction)(id lhs, id rhs), NSArray* nonemptyList);

/*!
	Returns false iff the result of applying block to each object in preimage is false.
	Computes the result in a short-circuit manner in the order in which the objects appear in the preimage.
	Informally, this is block(preimage_0) || block(preimage_1) || ... with the usual short circuiting.
*/
bool disjoinImageUnderBooleanBlock(bool(^booleanBlock)(id), NSArray* preimage);

/*!
	Returns true iff the result of applying block to each object in preimage is true.
	Computes the result in a short-circuit manner in the order in which the objects appear in the preimage.
	Informally, this is block(preimage_0) && block(preimage_1) && ... with the usual short circuiting.
*/
bool conjoinImageUnderBooleanBlock(bool(^booleanBlock)(id), NSArray* preimage);

//!	A generic zip function
/*!
	zip takes, as arguments, two lists (NSArray* instances).
	It returns a list of the pairs where the first element in each pair comes from the first list and the second element in each pair comes from the second list.
	NSArrays of length 2 are used for pairs (Objective-C doesn't have tuples, and NSArray* works for all tuple types).
	
	In Haskell:
	\code
	zip              :: [a] -> [b] -> [(a,b)]
	zip              =  zipWith (,)
	\endcode
	\param	lhsList	the list of values to be used as first elements in the pairs in the result.
	\param	rhsList the list of values to be used as second elements in the pairs in the result.
*/
NSArray* zip(NSArray* lhsList, NSArray* rhsList);

//!	A generic zipWith function.
/*!
	zipWith takes, as arguments, a zipper function (variably typed function of two arguments of variable type using blocks), and two lists (NSArray* instances).
	It returns a list of the results of applying the zipper function to each pair of elements with equal index in each list.
	
	In Haskell:
	\code
	zipWith          :: (a->b->c) -> [a]->[b]->[c]
	zipWith z (a:as) (b:bs)
					 =  z a b : zipWith z as bs
	zipWith _ _ _    =  []
	\endcode
	\param	zipper	the zipper function as a variably typed function of two arguments of variable type using blocks.
	\param	lhsList	the list of values to be used as the lhs argument when forming the result.
	\param	rhsList the list of values to be used as the rhs argument when forming the result.
*/
NSArray* zipWith(id(^zipper)(id lhs, id rhs), NSArray* lhsList, NSArray* rhsList);

//!	A generic unzip function.
/*!
	unzip takes a list of pairs and returns a pair of lists.
	In Haskell:
	\code
	unzip            :: [(a,b)] -> ([a],[b])
	unzip            =  foldr (\(a,b) ~(as,bs) -> (a:as,b:bs)) ([],[])
	\endcode
	\param	pairs	the list of pairs (NSArray* instances with length-2 NSArray* instances as objects).
	If the zipper function returns nil for any of its input pairs, the whole thing blows up and returns nil.
*/
NSArray* unzip(NSArray* pairs);

//!	A generic flatten function.
/*!
	flatten takes a list of lists (of lists...) and removes the (outermost layer of) inner square brackets.
*/
NSArray* flatten(NSArray* arrays);

//!	A function which takes an array of objects and returns a dictionary whose keys are the results of applying projectionBlock to the objects in the array and whose objects are the lists of objects from the original array with the same projection, in the order in which they came from the original array.
/*!
	If the projection block returns nil, the whole thing is nil.
*/
NSDictionary* inverseImageArraysByProjectionWithBlock(NSArray* array, id(^projectionBlock)(id));

//!	A function which takes an array of objects and returns a dictionary whose keys are the results of sending projectionSelector to the objects in the array and whose objects are the lists of objects from the original array with the same projection, in the order in which they came from the original array.
/*!
	If the projection selector returns nil, the whole thing is nil.
*/
NSDictionary* inverseImageArraysByProjectionWithSelector(NSArray* array, SEL projectionSelector);

//!	A function which merges two dictionary, merging the subdictionaries any time two keys collide (or returning nil if the colliding objects are not dictionaries or themselves collide).
NSDictionary* mergeDictionaries(NSDictionary* dictionary0, NSDictionary* dictionary1);

//!	An ad-hoc polymorphic function which takes two arrays and concatenates them or takes two dictionaries and merges them (returning nil if collisions blah blah blah).
id mergeDictionariesAppendArrays(id lhs, id rhs);

//!	An ad-hoc polymorphic function which takes two two sets and (disjoint) unites them or takes two arrays and concatenates or takes two dictionaries and merges them (returning nil if blablabla).
id mergeDictionariesAppendArraysUniteSets(id lhs, id rhs);

id mergeJSON(id lhs, id rhs);

#pragma mark	--Concurrency--

//!	Assuming referential transparency of the input function, does the same thing as map, but does it concurrently.
NSArray* concurrentMap(id(^function)(id x), NSArray* preimage);

NSArray* concurrentMapWithSelector(SEL selector, NSArray* preimage);

#pragma mark	--Unsafe--

//!	An unsafe (faster) version of map.
/*!	This will crash if the function returns nil for any element of the preimage.	*/
NSArray*	unsafeMap(id(^function)(id), NSArray* preimage);

//!	An unsafe version of mapWithSelector.
/*!	This will crash if the function returns nil for any element of the preimage.	*/
NSArray*	unsafeMapWithSelector(SEL selector, NSArray* preimage);

#pragma mark	--NSArray(Generics)--

/*!	\category NSArray(Generics)
	\abstract A category on NSArray to provide Haskelly functional programming functionality with respect to (parametrically polymorphic or very lucky) arrays.
	Ad hoc polymorphism will behave in an ad hoc manner.
*/
@interface NSArray(Generics)

//map
+(NSArray*)mapBlock:(id(^)(id x))block overArray:(NSArray*)array;	//!<	This is map for blocks.
+(NSArray*)mapSelector:(SEL)selector overArray:(NSArray*)array;	//!<	This is map for selectors.

//filter
+(NSArray*)filterBlock:(bool(^)(id x))block overArray:(NSArray*)array;	//!<	This is filter.

//fold
+(id)foldlWithBlock:(id(^)(id lhs, id rhs))block zero:(id)zero overArray:(NSArray*)array;	//!<	This is foldl.
+(id)foldrWithBlock:(id(^)(id lhs, id rhs))block zero:(id)zero overArray:(NSArray*)array;	//!<	This is foldr.
+(id)foldl1WithBlock:(id(^)(id lhs, id rhs))block overArray:(NSArray*)array;	//!<	This is foldl1.
+(id)foldr1WithBlock:(id(^)(id lhs, id rhs))block overArray:(NSArray*)array;	//!<	This is foldr1.

//!	reorder
/*!
	These methods do not directly sort a list using a comparator to project.
	Instead, they construct a dictionary whose keys are the image of the list under a projection function and whose values are list of objects from the original list with the same projection.
	Then they sort the keys using a comparator ON THE PROJECTIONS (which can assume that the inputs are not equal).
	Then they map to get a list of lists.
	Then they flatten the list of lists to get the result.
	A sorting function is used once on a list which is possibly smaller than the original list.
*/
-(NSArray*)arrayByReorderingWithProjectionBlock:(id(^)(id))projectionBlock comparisonSelector:(SEL)comparisonSelector;

//!	reorder
/*!
	These methods do not directly sort a list using a comparator to project.
	Instead, they construct a dictionary whose keys are the image of the list under a projection function and whose values are list of objects from the original list with the same projection.
	Then they sort the keys using a comparator ON THE PROJECTIONS (which can assume that the inputs are not equal).
	Then they map to get a list of lists.
	Then they flatten the list of lists to get the result.
	A sorting function is used once on a list which is possibly smaller than the original list.
*/
-(NSArray*)arrayByReorderingWithProjectionBlock:(id(^)(id))projectionBlock comparisonBlock:(NSComparisonResult(^)(id, id))comparisonBlock;

//!	reorder
/*!
	These methods do not directly sort a list using a comparator to project.
	Instead, they construct a dictionary whose keys are the image of the list under a projection function and whose values are list of objects from the original list with the same projection.
	Then they sort the keys using a comparator ON THE PROJECTIONS (which can assume that the inputs are not equal).
	Then they map to get a list of lists.
	Then they flatten the list of lists to get the result.
	A sorting function is used once on a list which is possibly smaller than the original list.
*/
-(NSArray*)arrayByReorderingWithProjectionSelector:(SEL)projectionSelector comparisonSelector:(SEL)comparisonSelector;

//!	reorder
/*!
	These methods do not directly sort a list using a comparator to project.
	Instead, they construct a dictionary whose keys are the image of the list under a projection function and whose values are list of objects from the original list with the same projection.
	Then they sort the keys using a comparator ON THE PROJECTIONS (which can assume that the inputs are not equal).
	Then they map to get a list of lists.
	Then they flatten the list of lists to get the result.
	A sorting function is used once on a list which is possibly smaller than the original list.
*/
-(NSArray*)arrayByReorderingWithProjectionSelector:(SEL)projectionSelector comparisonBlock:(NSComparisonResult(^)(id, id))comparisonBlock;

//!	reorder
/*!
	These methods do not directly sort a list using a comparator to project.
	Instead, they construct a dictionary whose keys are the image of the list under a projection function and whose values are list of objects from the original list with the same projection.
	Then they sort the keys using a comparator ON THE PROJECTIONS (which can assume that the inputs are not equal).
	Then they map to get a list of lists.
	Then they flatten the list of lists to get the result.
	A sorting function is used once on a list which is possibly smaller than the original list.
*/
-(NSArray*)arrayByReorderingInReverseWithProjectionBlock:(id(^)(id))projectionBlock comparisonSelector:(SEL)comparisonSelector;

//!	reorder
/*!
	These methods do not directly sort a list using a comparator to project.
	Instead, they construct a dictionary whose keys are the image of the list under a projection function and whose values are list of objects from the original list with the same projection.
	Then they sort the keys using a comparator ON THE PROJECTIONS (which can assume that the inputs are not equal).
	Then they map to get a list of lists.
	Then they flatten the list of lists to get the result.
	A sorting function is used once on a list which is possibly smaller than the original list.
*/
-(NSArray*)arrayByReorderingInReverseWithProjectionBlock:(id(^)(id))projectionBlock comparisonBlock:(NSComparisonResult(^)(id, id))comparisonBlock;
//!	reorder
/*!
	These methods do not directly sort a list using a comparator to project.
	Instead, they construct a dictionary whose keys are the image of the list under a projection function and whose values are list of objects from the original list with the same projection.
	Then they sort the keys using a comparator ON THE PROJECTIONS (which can assume that the inputs are not equal).
	Then they map to get a list of lists.
	Then they flatten the list of lists to get the result.
	A sorting function is used once on a list which is possibly smaller than the original list.
*/

//!	reorder
/*!
	These methods do not directly sort a list using a comparator to project.
	Instead, they construct a dictionary whose keys are the image of the list under a projection function and whose values are list of objects from the original list with the same projection.
	Then they sort the keys using a comparator ON THE PROJECTIONS (which can assume that the inputs are not equal).
	Then they map to get a list of lists.
	Then they flatten the list of lists to get the result.
	A sorting function is used once on a list which is possibly smaller than the original list.
*/
-(NSArray*)arrayByReorderingInReverseWithProjectionSelector:(SEL)projectionSelector comparisonSelector:(SEL)comparisonSelector;

//!	reorder
/*!
	These methods do not directly sort a list using a comparator to project.
	Instead, they construct a dictionary whose keys are the image of the list under a projection function and whose values are list of objects from the original list with the same projection.
	Then they sort the keys using a comparator ON THE PROJECTIONS (which can assume that the inputs are not equal).
	Then they map to get a list of lists.
	Then they flatten the list of lists to get the result.
	A sorting function is used once on a list which is possibly smaller than the original list.
*/
-(NSArray*)arrayByReorderingInReverseWithProjectionSelector:(SEL)projectionSelector comparisonBlock:(NSComparisonResult(^)(id, id))comparisonBlock;

//array
-(id)headObject;	//!<	This is headObject for arrays.
-(NSArray*)tailObjects;	//!<	This is tailObjects for arrays.
-(NSArray*)initObjects;	//!<	This is initObjects (not the Objective-C init) for arrays.
//last object already exists lol.

-(NSArray*)reverseObjects;	//!<	This is reverseObjects for arrays.

//map
-(NSArray*)imageUnderBlock:(id(^)(id x))block;		//!<	This is per-instance map, but due to retarded Objective-C naming conventions, it is named thus.
-(NSArray*)imageUnderSelector:(SEL)selector;	//!<	This is also per-instance map, but using an Objective-C selector instead of a block.

//filter
-(NSArray*)filtrateUnderBlock:(bool(^)(id x))block;	//!<	This is per-instance filter.

//fold
-(id)valueByFoldingLeftWithBlock:(id(^)(id a, id b))block zero:(id)zero;	//!<	This is per-instance foldl
-(id)valueByFoldingRightWithBlock:(id(^)(id a, id b))block zero:(id)zero;	//!<	This is per-instance foldr.
-(id)valueByFoldingLeftWithBlock:(id(^)(id a, id b))block;	//!<	This is per-instance foldl1.
-(id)valueByFoldingRightWithBlock:(id(^)(id a, id b))block;	//!<	This is per-instance foldr1.

@end

#pragma mark	--NSDictionary(Generics)--

//!	A category for generics involving associative arrays (NSDictionary*).
@interface NSDictionary(Generics)

+(NSDictionary*)dictionaryByApplyingBlock:(id(^)(id key))keyBlock toEachKeyAndBlock:(id(^)(id object))objectBlock toEachObjectInDictionary:(NSDictionary*)dictionary;	//!<	given a dictionary, returns a dictionary containing the image of the original keys under keyBlock for keys and the image of the objects under objectBlock for objects.
+(NSDictionary*)dictionaryByApplyingSelector:(SEL)keySelector toEachKeyAndSelector:(SEL)objectSelector toEachObjectInDictionary:(NSDictionary*)dictionary;	//!<	given a dictionary, returns a dictionary containing the image of the original keys under keySelector for keys and the image of the objects under objectSelector for objects.
+(NSDictionary*)dictionaryByMergingDictionary0:(NSDictionary*)dictionary0 withDictionary1:(NSDictionary*)dictionary1;

-(NSDictionary*)resultOfApplyingToEachKeyTheBlock:(id(^)(id key))keyBlock andToEachObjectTheBlock:(id(^)(id object))objectBlock;	//!<	returns a dictionary containing the image of the original keys under keyBlock for keys and the image of the objects under objectBlock for objects.
-(NSDictionary*)resultOfApplyingToEachKeyTheSelector:(SEL)keySelector andToEachObjectTheSelector:(SEL)objectSelector;	//!<	returns a dictionary containing the image of the original keys under keySelector for keys and the image of the objects under objectSelector for objects.

@end

#pragma mark	--NSDictionary(Morphism)--

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

//TODO: rename these as unsafe, do safe versions.

//!	A category for treating a NSDictionary as a morphism.
@interface NSDictionary(Morphism)

@end

