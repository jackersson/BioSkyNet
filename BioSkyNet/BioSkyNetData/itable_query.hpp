#ifndef ITable_Query_IO_INCLUDED
#define ITable_Query_IO_INCLUDED

#include <string>
#include "Poco/Format.h"
namespace SmartBio
{
	namespace Interfaces
	{		
		class ITableQuery
		{
		public:		
			virtual const std::string& tableName  () = 0; 
			virtual std::string        createTable() = 0;

		/*	ITableQuery();
			virtual ~ITableQuery();*/

		public:
						
			std::string unique()
			{
				std::string query = Poco::cat(std::string(" SELECT max(Id) FROM "), tableName());
				return query;
			}
					
			std::string select( std::string what = "*", std::string qwhere = "")
			{				
				std::string sl("");
				if (qwhere == "")
			  	Poco::format(sl, "SELECT %s FROM %s", what, tableName());
				else 
				  Poco::format(sl, "SELECT %s FROM %s WHERE %s ", what, tableName(), qwhere);
				return sl;
			}

			std::string insertComplex()
			{
				std::string ins("");
				std::vector<std::string> columns_temp;

				for (auto it = columns_.begin(); it != columns_.end(); ++it)
				{
					std::string temp = Poco::cat(std::string(":"), (*it));
					columns_temp.push_back(temp);
				}				

				std::string complex_cols = Poco::cat(std::string(", "), columns_temp.begin(), columns_temp.end());
				Poco::format(ins, "INSERT INTO %s VALUES( %s )", tableName(), complex_cols);
				return ins;
			}

		  std::string insertCustom(std::string what )
			{				
				std::string ins("");				
				std::string cols = Poco::cat(std::string(", "), columns_.begin(), columns_.end());
				Poco::format(ins, "INSERT INTO %s ( %s ) VALUES ( %s )", tableName(), cols, what);
				return ins;
			}

			std::string update(std::string qwhere, std::string what = "*")
			{
				std::string ins("");
				std::string cols = Poco::cat(std::string(", "), columns_.begin(), columns_.end());
				std::string wh = (what == "*") ? cols : what;
				Poco::format(ins, "UPDATE %s SET ( %s ) WHERE %s", tableName(), wh, qwhere);
				return ins;
			}

			std::string deleteRecord( std::string qwhere)
			{
				std::string ins("");
				Poco::format(ins, "DELETE FROM %s WHERE ( %s )", tableName(), qwhere);
				return ins;
			}

		protected:
			bool initialized_;
			std::vector<std::string> columns_;

			std::string create(std::string columns)
			{
				std::string cr("");
				Poco::format(cr, "CREATE TABLE IF NOT EXISTS %s ( %s )", tableName(), columns);
				return cr;
			}

			std::string formatColumn( int index
				                      , std::string type    
				                      , std::string isnull  = ""
															, std::string primary = "")
			{
				std::string fr("");
				if (columns_.size() > index)								
					Poco::format(fr, " %s %s %s %s", columns_[index], type, isnull, primary);				
				return fr;
			}

			std::string typeNText()
			{
				std::string ins("ntext");			
				return ins;
			}

			std::string typeInteger()
			{
				std::string ins("INTEGER");
				return ins;
			}

			std::string typeBigInteger()
			{
				std::string ins("BIGINTEGER");
				return ins;
			}

			std::string typeFloat()
			{
				std::string ins("float");
				return ins;
			}

			std::string typeTinyInteger()
			{
				std::string ins("tinyint");
				return ins;
			}

			std::string typeNotNull()
			{
				std::string ins("NOT NULL");
				return ins;
			}

			std::string typeDatetime()
			{
				std::string ins("datetime");
				return ins;
			}

			std::string typePrimaryKey()
			{
				std::string ins("PRIMARY KEY");
				return ins;
			}

			private:
				virtual void  createColumns() = 0;
				
		};
	}
}

#endif
