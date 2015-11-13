#ifndef Bio_Visitor_Table_INCLUDED
#define Bio_Visitor_Table_INCLUDED

#include "itable_query.hpp"

namespace SmartBio
{
	namespace Data
	{
		class BioDbIO;
		class BioVisitor;
		class BioVisitorTable : public Interfaces::ITableQuery
		{
		public:
		  ~BioVisitorTable()	{	}

		private:

			friend class BioDbIO;
			friend class BioVisitor;

			static const std::string TABLE_NAME;

			BioVisitorTable();

			const std::string& tableName();		

			std::string createTable  ();
			void        createColumns();

		};
	}
}

#endif
