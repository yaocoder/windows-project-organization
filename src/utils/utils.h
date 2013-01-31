#include <string>
#include <vector>

namespace utils
{
	static void MySplitString(	const std::string & str,
		const std::string & strDelim,
		std::vector<std::string> & vectValues )
	{
		using namespace std;

		vectValues.clear();

		if( str.size() && strDelim.size() )
		{
			std::string::size_type pos = 0;
			std::string::size_type posStart = 0;
			while( pos != string::npos )
			{
				pos = str.find( strDelim, posStart );
				std::string::const_pointer pStart = str.c_str() + posStart;
				if( pos == string::npos )
				{
					vectValues.push_back( string( pStart ) );
				} else
				{
					vectValues.push_back( string( pStart, pos - posStart ) );
					posStart = pos + strDelim.size();
				}
			}
		}
	}
}

