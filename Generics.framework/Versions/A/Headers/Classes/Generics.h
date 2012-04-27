//
//  Generics.h
//  SMNStaff
//
//  Created by Ryan Tsukamoto on 3/21/12.
//  Copyright (c) 2012 Miso Media. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Generics/NSArray+Generics.h>
#import <Generics/NSDictionary+Generics.h>
#import <Generics/NSDictionary+Morphism.h>

//!	\file Generics.h has Haskelly goodness for all!  All code examples come from Haskell's Prelude module.

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
*/
NSArray* mapWithSelector(SEL selector, NSArray* preimage);

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

//!	Document this!
/*!

*/
NSArray* mapTuples(NSArray* functionsTuple, NSArray* tuples);

//!	Document this!
/*!

*/
NSArray* mapTuplesWithSelector(SEL* selectorsTuple, NSArray* tuples);

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
*/
NSArray* unzip(NSArray* pairs);

//!	A generic flatten function.
/*!
	flatten takes a list of lists and removes the inner square brackets.  This would be the associativity of multiplication for monoids.
*/
NSArray* flatten(NSArray* arrays);

NSDictionary* inverseImageArraysByProjectionWithBlock(NSArray* array, id(^projectionBlock)(id));

NSDictionary* inverseImageArraysByProjectionWithSelector(NSArray* array, SEL projectionSelector);
