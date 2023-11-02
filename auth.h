/*
 Copyright (c) 2023 William He (https://github.com/fwilliamhe/)

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef CF_AUTH
#define CF_AUTH

#include <iostream>
#include <cstring>
#include <random>
#include "md5.h"


std::mt19937 rnd(time(nullptr));

int rand(int l,int r) {
    return rnd() % (r - l + 1) + l;
}

std::string ito36text(long long x) {
    std::string rt="";
    while (x){
        long long c = x % 36;
        if (c < 10) rt += (char)(c + '0');
        else rt += (char)(c - 10 + 'a');
        x /= 36;
    }
    return rt;
}

std::string randomNumber() {
    return ito36text(abs(rnd())).substr(2);
}

std::string randomToken() {
    std::string rt = "";
    while (rt.length() < 18) {
        rt += randomNumber();
    }
    return rt.substr(0, 18);
}

namespace codeforces {
    /* 
        Get tta for codeforces
        Notes : cookie is cookies['39ce7']
        Upd time : Nov 1 2023 19:52:51 (PDT)
    */
    int get_tta(std::string cookie) {
        int tta = 0; const int P = 1009;
        for (int i = 0; i < cookie.length(); ++i) {
            tta = (tta + (i + 1) % P * (i + 2) % P * cookie[i] % P) % P;
            if (i % 3 == 0) (tta += 1) %= P;
            if (i % 2 == 0) (tta *= 2) %= P;
            if (i > 0) (tta -= (cookie[i / 2] / 2) % P * (tta % 5) % P - P ) %= P;
        }
        return tta;
    }
    /* Generate bfaa 
       Random string is also valid. Users can stored different sessions with MD5. 
    */
    std::string generate_bfaa() {
        std::string random_string = randomToken();
        return hash::MD5(random_string).hexdigest();
        // return hash::MD5( <UserSession> ).hexdigest(); 
    }
    /* Generate ftaa */
    std::string generate_ftaa() {
        return randomToken();
    }
}

#endif