#ifndef BDN_init_H_
#define BDN_init_H_

#include <bdn/config.h>

#define BDN_IMPLEMENTS virtual public

// This is slightly complicated because of the intricacies of the
// C preprocessor. In order for the preprocessor to actually expand
// the parameters and concatenate them we need several layers of indirection.
#define BDN_APPEND_LINE_IMPL_1(dummy, finalName) finalName
#define BDN_APPEND_LINE_IMPL_2(a, b) BDN_APPEND_LINE_IMPL_1(~, a##b)
#define BDN_APPEND_LINE_IMPL_3(a, b) BDN_APPEND_LINE_IMPL_2(a, b)

/** \def BDN_APPEND_LINE(baseName)

    Appends the line number of the source file that this is used on to the
    specified base name. This can be used to generate somewhat unique names.

    */
#define BDN_APPEND_LINE(baseName) BDN_APPEND_LINE_IMPL_3(baseName, __LINE__)

namespace bdn
{
    /** A dummy function that does nothing. This can be used in macros and the
       like when an actual instruction (rather than an empty statement) is
       needed.*/
    inline void doNothing() {}
}

#include <bdn/IBase.h>
#include <bdn/P.h>
#include <bdn/Base.h>

#include <bdn/newObj.h>

#include <bdn/Mutex.h>

#include <bdn/SafeInit.h>

#include <bdn/TextOutStream.h>

#include <bdn/String.h>

#include <bdn/ProgrammingError.h>
#include <bdn/InvalidArgumentError.h>
#include <bdn/OutOfRangeError.h>
#include <bdn/SystemError.h>

#include <bdn/cast.h>

#include <bdn/safeStatic.h>

#include <bdn/destruct.h>

#include <bdn/WeakP.h>

#include <bdn/func.h>

// StringBuffer provides global operators for String
// that allow convenient formatting. So we always need it.
#include <bdn/StringBuffer.h>

#endif
