/*
 * ModSecurity, http://www.modsecurity.org/
 * Copyright (c) 2015 Trustwave Holdings, Inc. (http://www.trustwave.com/)
 *
 * You may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * If any of the files related to licensing are missing or if you have any
 * other questions related to licensing please contact Trustwave Holdings, Inc.
 * directly using the email address security@modsecurity.org.
 *
 */

#include "actions/transformations/remove_nulls.h"

#include <string.h>

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

#include "modsecurity/assay.h"
#include "actions/transformations/transformation.h"
#include "src/utils.h"

namespace ModSecurity {
namespace actions {
namespace transformations {


std::string RemoveNulls::evaluate(std::string value,
    Assay *assay) {
    int64_t i;

    i = 0;
    while (i < value.size()) {
        if (value.at(i) == '\0') {
            value.erase(i, 1);
        } else {
            i++;
        }
    }

    return value;
}


}  // namespace transformations
}  // namespace actions
}  // namespace ModSecurity