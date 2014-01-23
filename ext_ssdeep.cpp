/**
 * Based on PECL ssdeep extension
 * http://pecl.php.net/ssdeep
 * @author Simon Holywell <treffynnon@php.net>
 */

#include "hphp/runtime/base/base-includes.h"
#include "hphp/runtime/base/zend-string.h"

#include "hphp/runtime/base/runtime-option.h"
#include "hphp/runtime/server/server-stats.h"
#include "hphp/runtime/ext/ext_string.h"

#include <cinttypes>
#include <fuzzy.h>

namespace HPHP {
    static String HHVM_FUNCTION(ssdeep_info) {
        return "H";
    }

    class ssdeepExtension: public Extension {
        public:
            ssdeepExtension(): Extension("ssdeep") { /* null */ }
            virtual void moduleInit() {
                HHVM_FE(ssdeep_info);
                loadSystemlib();
            }
    } s_ssdeep_extension;
    HHVM_GET_MODULE(ssdeep);
}
