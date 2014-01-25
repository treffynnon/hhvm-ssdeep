/**
 * Based on PECL ssdeep extension
 * http://pecl.php.net/ssdeep
 * @author Simon Holywell <treffynnon@php.net>
 */

#include "hphp/runtime/base/base-includes.h"
#include <fuzzy.h>

namespace HPHP {
    static Variant HHVM_FUNCTION(ssdeep_fuzzy_hash, const String& to_hash) {
        char* hash = (char*) smart_malloc(FUZZY_MAX_RESULT);
        int to_hash_len = to_hash.length();
        const unsigned char* to_hash_char =
            reinterpret_cast<const unsigned char*>(to_hash.c_str());
        if (0 != fuzzy_hash_buf(to_hash_char, to_hash_len, hash)) {
            return false;
        } else {
            return String(hash);
        }
    }

    static Variant HHVM_FUNCTION(ssdeep_fuzzy_compare, const String& signature1, const String& signature2) {
        int64_t match;
        match = fuzzy_compare(signature1.c_str(), signature2.c_str());
        if(match < 0 || match > 100) {
            return false;
        } else {
            return match;
        }
    }

    static Variant HHVM_FUNCTION(ssdeep_fuzzy_hash_filename, const String& file_name) {
        char* hash = (char*) smart_malloc(FUZZY_MAX_RESULT);
        if (0 != fuzzy_hash_filename(file_name.c_str(), hash)) {
            return false;
        } else {
            return String(hash);
        }
    }

    class ssdeepExtension: public Extension {
        public:
            ssdeepExtension(): Extension("ssdeep") { /* null */ }
            virtual void moduleInit() {
                HHVM_FE(ssdeep_fuzzy_hash);
                HHVM_FE(ssdeep_fuzzy_compare);
                HHVM_FE(ssdeep_fuzzy_hash_filename);
                loadSystemlib();
            }
    } s_ssdeep_extension;
    HHVM_GET_MODULE(ssdeep);
}
