#ifndef Bio_PhotoItem_Table_INCLUDED
#define Bio_PhotoItem_Table_INCLUDED

#include "itable_query.hpp"

namespace SmartBio
{
	namespace Data
	{
		class BioDbIO;
		class BioPhotoItem;
		class BioPhotoItemTable : public Interfaces::ITableQuery
		{
		public:
			~BioPhotoItemTable()	{	}

		private:
			static const std::string TABLE_NAME;

			friend class BioDbIO     ;
			friend class BioPhotoItem;

			BioPhotoItemTable();		

			const std::string& tableName    ();						
			std::string        createTable  ();
			void               createColumns();
		};
	}
}

#endif
