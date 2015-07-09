/*
 * ccCommon.cpp
 *
 *  Created on: 12-09-2013
 *      Author: piotr
 */

#include "ccCommon.h"
#include <fstream>
#include "../vendor/md5/md5.h"
#include <pcre.h>

namespace ccFramework {
    std::string array_pattern = "\\[[^\\]]*\\]";
    pcre *re;

 ccCommon::ccCommon() {
	// TODO Auto-generated constructor stub

}

ccCommon::~ccCommon() {
	// TODO Auto-generated destructor stub
}

std::string ccCommon::md5hash(std::string val) {
	MD5 md5;
	md5.update((unsigned char *)val.c_str(), val.length());
	md5.finalize();
	char *tmp = md5.hex_digest();
	std::string ret = tmp;
	delete tmp;
	return ret;
}

bool ccCommon::file_exists(std::string filename) {
	bool ret = false;
	std::ifstream ifile(filename.c_str());
	if (ifile) {
		ret = true;
		ifile.close();
	}
	return ret;
}
/*
std::string ccCommon::ltrim(std::string s) {
	s.erase(s.begin(),
			std::find_if(s.begin(), s.end(),
					std::not1(std::ptr_fun<int, int>(std::isspace))));
	return s;
}

// trim from end
std::string ccCommon::rtrim(std::string s) {
	s.erase(
			std::find_if(s.rbegin(), s.rend(),
					std::not1(std::ptr_fun<int, int>(std::isspace))).base(),
			s.end());
	return s;
}
*/

std::string ccCommon::rtrim(std::string s, std::string delimiters)
{
   s.erase( s.find_last_not_of( delimiters ) + 1 );
   return s;
}

std::string ccCommon::ltrim(std::string s,  std::string delimiters)
{
   s.erase( 0, s.find_first_not_of( delimiters ) );
   return s;
}

std::string ccCommon::trim(std::string s, std::string delimiters)
{
    //s.erase( s.find_last_not_of( delimiters ) + 1 ).erase( 0, s.erase( s.find_last_not_of( delimiters ) + 1 ).find_first_not_of( delimiters ) );
    return ltrim(rtrim(s));
}

// trim from both ends
//std::string ccCommon::trim(std::string s) {
//	return ltrim(rtrim(s));
//}

std::string ccCommon::UriEncode(const std::string & sSrc) {
	const char DEC2HEX[16 + 1] = "0123456789ABCDEF";
	const unsigned char * pSrc = (const unsigned char *) sSrc.c_str();
	const int SRC_LEN = sSrc.length();
	unsigned char * const pStart = new unsigned char[SRC_LEN * 3];
	unsigned char * pEnd = pStart;
	const unsigned char * const SRC_END = pSrc + SRC_LEN;

	for (; pSrc < SRC_END; ++pSrc) {
		if (SAFE[*pSrc])
			*pEnd++ = *pSrc;
		else {
// escape this char
			*pEnd++ = '%';
			*pEnd++ = DEC2HEX[*pSrc >> 4];
			*pEnd++ = DEC2HEX[*pSrc & 0x0F];
		}
	}

	std::string sResult((char *) pStart, (char *) pEnd);
	delete[] pStart;
	return sResult;
}

std::string ccCommon::UriDecode(const std::string & sSrc) {
// Note from RFC1630: "Sequences which start with a percent
// sign but are not followed by two hexadecimal characters
// (0-9, A-F) are reserved for future extension"

	std::string src = ccCommon::replaceAll("+"," ",sSrc);
	const unsigned char * pSrc = (const unsigned char *) src.c_str();
	const int SRC_LEN = src.length();
	const unsigned char * const SRC_END = pSrc + SRC_LEN;
// last decodable '%'
	const unsigned char * const SRC_LAST_DEC = SRC_END - 2;

	char * const pStart = new char[SRC_LEN];
	char * pEnd = pStart;

	while (pSrc < SRC_LAST_DEC) {
		if (*pSrc == '%') {
			char dec1, dec2;
			if (-1 != (dec1 = HEX2DEC[*(pSrc + 1)])
					&& -1 != (dec2 = HEX2DEC[*(pSrc + 2)])) {
				*pEnd++ = (dec1 << 4) + dec2;
				pSrc += 3;
				continue;
			}
		}

		*pEnd++ = *pSrc++;
	}

// the last 2- chars
	while (pSrc < SRC_END)
		*pEnd++ = *pSrc++;

	std::string sResult(pStart, pEnd);
	delete[] pStart;

	return sResult;
}



std::string ccCommon::htmlTag(std::string name, std::string value,
		std::map<std::string, std::string> attr) {

	std::string ret = "<"+name;

	for (std::map<std::string, std::string>::iterator it = attr.begin();
			it != attr.end(); ++it) {
		ret += " "+it->first+"=\""+it->second+"\"";
	}

	if (value.size()>0) {
		ret += +">"+value;
		ret += "</"+name+">";
	} else {
		ret += "/>";
	}
	return ret;
}

std::string ccCommon::htmlTag(std::string name, std::string value) {
	return "<"+name+">"+value+"</"+name+">";

}

double ccCommon::string2double(std::string value) {
	double tmp;
	std::istringstream ( value ) >> tmp;
	return tmp;
}

int ccCommon::string2int(std::string value) {
	int tmp;
	std::istringstream ( value ) >> tmp;
	return tmp;
}

std::string ccCommon::int2string(int value, std::string format) {
	char buffer [50];
	sprintf (buffer, format.c_str() ,value);
	return buffer;
}

std::string ccCommon::double2string(double value, std::string format) {
	char buffer [50];
	sprintf (buffer, format.c_str() ,value);
	return buffer;
}



std::string ccCommon::replaceAll(std::string from, std::string to, std::string str)  {
    std::string ret = str;
	if(from.empty())
        return "";
    size_t start_pos = 0;
    while((start_pos = ret.find(from, start_pos)) != std::string::npos) {
    	ret.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }

    return ret;
}

std::vector<std::string> ccCommon::explode(const std::string& s,
		char delim) {
    std::vector<std::string> result;
    std::istringstream iss(s);

    for (std::string token; std::getline(iss, token, delim);) {
        result.push_back(std::move(token));
    }

    return result;
}
    std::vector<std::string> ccCommon::array_elements(std::string const & s) {
        std::vector<std::string> ret;
        const char *error;
        int   erroffset;
        int   rc;
        int   ovector[100];
        unsigned int offset = 0;
        unsigned int len    = s.length();

        size_t bracket_start_pos = s.find_first_of("[");
        
        if (bracket_start_pos == string::npos) {
        
            ret.push_back(s);
            return ret;
        } else {
            size_t bracket_end_pos = s.find_first_of("]",bracket_start_pos+1);
            //check if string has valid brackets 
            if (bracket_end_pos != string::npos) {
                ret.push_back(s.substr(0,bracket_start_pos));
            } else {
                ret.push_back(s);
                return ret;
            }
        }
        
        //get all data from brackets
        if (!re)
        {
            re = pcre_compile (array_pattern.c_str(),          /* the pattern */
                               PCRE_MULTILINE,
                               &error,         /* for error message */
                               &erroffset,     /* for error offset */
                               0);             /* use default character tables */
            if (!re) {
                printf("pcre_compile failed (offset: %d), %s\n", erroffset, error);
                return ret;
            }
        }

        while (offset < len && (rc = pcre_exec(re, 0, s.c_str(), len, offset, 0, ovector, sizeof(ovector))) >= 0)
        {
            for(int i = 0; i < rc; ++i)
            {
                ret.push_back(s.substr(ovector[2*i]+1,ovector[2*i+1] - ovector[2*i]-2));
            }
            offset = ovector[1];
        }
        return ret;
    }



} /* namespace ccFramework */


