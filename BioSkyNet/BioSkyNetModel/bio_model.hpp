#ifndef Bio_Model_INCLUDED
#define Bio_Model_INCLUDED

#include "../SmartInterfaces/ilogger.hpp"
#include "../SmartInterfaces/imodel.hpp"
#include "../SmartInterfaces/patterns.hpp"

#include "../BioSkyNetData/bio_db_io.hpp"

namespace SmartBio {
	namespace Model
	{
		
		class BioModel : public Interfaces::IModel
			             , public Interfaces::UncopyableSingleton < BioModel >
		{
			friend class Interfaces::IModel;
			friend class Interfaces::UncopyableSingleton < BioModel > ;

		public:
			virtual ~BioModel();

			BioModel& get()
			{
				return *this;
			}

			Poco::SharedPtr<Interfaces::ILogger>& logger()
			{
				return logger_;
			}

			Poco::SharedPtr<Data::BioDbIO>& databaseEngine()
			{
				return db_engine_;
			}

		private:
			BioModel();
			void do_initialize() final;

		private:
			Poco::SharedPtr<Interfaces::ILogger> logger_;	
			Poco::SharedPtr<Data::BioDbIO>       db_engine_;
		};

	}
}


#endif