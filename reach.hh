/*
 Copyright (C) 2016 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 Basic demonstration of how to use the SystemConfiguration Reachablity APIs.
 */

#ifndef OSX_REACH_HH
#define OSX_REACH_HH

typedef void (*cbSignature)(int);

extern void StartReachabilityNotifier(cbSignature callback);
extern void StopReachabilityNotifier();

#endif /* OSX_REACH_HH */
