#include "stdafx.h"
#include "bio_db_io.hpp"

namespace SmartBio
{
	namespace Data
	{
		bool BioDbIO::initilalized = false;
		std::string BioDbIO::CONNECTION_STRING;
		std::map<std::string, Poco::SharedPtr<Interfaces::ITableQuery>> BioDbIO::table_queries_;
	}
}