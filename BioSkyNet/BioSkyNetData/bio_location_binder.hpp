#ifndef Bio_Location_Binder_INCLUDED
#define Bio_Location_Binder_INCLUDED

#include "bio_location.hpp"

namespace Poco
{
	namespace Data
	{
		typedef SmartBio::Data::BioLocation LocationType;
		template < >
		class Poco::Data::TypeHandler<LocationType>
		{
		public:
			static void bind( std::size_t pos, const LocationType& obj
				              , AbstractBinder::Ptr pBinder, AbstractBinder::Direction dir);


			static void prepare( std::size_t pos, const LocationType& obj
				                 , AbstractPreparator::Ptr pPrepare);


			static std::size_t size();


			static void extract( std::size_t pos, LocationType& obj
				                 , const LocationType& defVal, AbstractExtractor::Ptr pExt);


		private:
			static const int DATABASE_COLUMNS_SIZE = 10;

			TypeHandler();
			~TypeHandler();
			TypeHandler(const TypeHandler&);
			TypeHandler& operator=(const TypeHandler&);

		};



	}
}

#endif

