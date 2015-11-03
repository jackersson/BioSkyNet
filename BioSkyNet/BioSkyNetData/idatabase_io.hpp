#ifndef IDatabase_IO_INCLUDED
#define IDatabase_IO_INCLUDED

#include "Poco/Data/Session.h"

namespace SmartBio
{
	namespace Interfaces
	{
		template <typename DBItemType>
		class IDatabaseIO
		{
		public: 
			virtual bool  write( std::vector<DBItemType>& data) = 0;
			virtual bool  read( std::vector<DBItemType>& data, std::string query) = 0;

			virtual bool write(DBItemType& data) = 0;
			//virtual bool read (DBItemType data) = 0;
		};
	}
}

#endif
