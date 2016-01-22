/*  This file is based on the Catch test framework. It has been adapted to
*  use existing boden parts where possible.
*
*  This single file is distributed under a license that is separate
*  from the rest of the library.
*  It is distributed under the Boost Software License, Version 1.0 (see below)
*
*  Modifications Copyright (c) Ashampoo Systems GmbH & Co. KG
*  Original version from Catch Copyright (c) 2012 Two Blue Cubes Ltd. All rights reserved.

Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

*/


#ifndef BDN_testMain_H_
#define BDN_testMain_H_

#include <bdn/test.h>

#ifndef __OBJC__

// Standard C/C++ main entry point
int main (int argc, char * argv[]) {
	return bdn::runTestSession( argc, argv );
}

#else // __OBJC__

// Objective-C entry point
int main (int argc, char * const argv[]) {
#if !BDN_ARC_ENABLED
	NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
#endif

	bdn::registerTestMethods();
	int result = runTestSession( argc, (char* const*)argv );

#if !BDN_ARC_ENABLED
	[pool drain];
#endif

	return result;
}

#endif // __OBJC__


#endif

