#include "stdafx.h"
#include "bio_photo_item_binder.hpp"


namespace Poco
{
	namespace Data
	{
		//typedef BioPerson PersonType;
		typedef Poco::Data::TypeHandler<PhotoItemType> BaseClass;


		void BaseClass::bind(std::size_t pos, const PhotoItemType& obj
			, AbstractBinder::Ptr pBinder, AbstractBinder::Direction dir)
		{
			poco_assert_dbg(!pBinder.isNull());

			pBinder->bind(pos++, obj.index()              ,dir);
			pBinder->bind(pos++, obj.photoPath()				 	,dir);
			pBinder->bind(pos++, obj.firPath()						,dir);
			pBinder->bind(pos++, obj.naturalSkinColor()	  ,dir);
			pBinder->bind(pos++, obj.gender()						  ,dir);
			pBinder->bind(pos++, obj.age()								,dir);
			pBinder->bind(pos++, obj.glasses()						,dir);
			pBinder->bind(pos++, obj.resolution()				  ,dir);
			pBinder->bind(pos++, obj.etnicity()        	  ,dir);
			pBinder->bind(pos++, obj.sampleQuality()      ,dir);
	


		}


		void BaseClass::prepare(std::size_t pos, const PhotoItemType& obj
			, AbstractPreparator::Ptr pPrepare)
		{
			//no-op (SQLite is prepare-less connector)
		}

		std::size_t BaseClass::size()
		{
			return BaseClass::DATABASE_COLUMNS_SIZE;
		}

		void BaseClass::extract(std::size_t pos, PhotoItemType& obj
			, const PhotoItemType& defVal, AbstractExtractor::Ptr pExt)
		{

			poco_assert_dbg(!pExt.isNull());

			std::string        photo_path         ;	
			std::string        fir_path					 	;
			bool               natural_skin_color	;
			int                gender						 	;
			int                age						 		;
			bool               glasses				 		;
			std::string        resolution				 	;
			int                etnicity         	;
			int                index            	;
			float              sample_quality     ;



			if (pExt->extract(pos++, index))
				obj.setIndex(index);
			else
				obj.setIndex(defVal.index());

			if (pExt->extract(pos++, photo_path))
				obj.setPhotoPath(photo_path);
			else
				obj.setPhotoPath(defVal.photoPath());

			if (pExt->extract(pos++, fir_path))
				obj.setFirPath(fir_path);
			else
				obj.setFirPath(defVal.firPath());

			if (pExt->extract(pos++, natural_skin_color))
				obj.setNaturalSkinColor(natural_skin_color);
			else
				obj.setNaturalSkinColor(defVal.naturalSkinColor());

			if (pExt->extract(pos++, gender))
				obj.setGender((SmartBio::Gender)(gender));
			else
				obj.setGender(defVal.gender());

			if (pExt->extract(pos++, age))
				obj.setAge(age);
			else
				obj.setAge(defVal.age());

			if (pExt->extract(pos++, glasses))
				obj.setGlasses(glasses);
			else
				obj.setGlasses(defVal.glasses());

			if (pExt->extract(pos++, resolution))
				obj.setResolution(resolution);
			else
				obj.setResolution(defVal.resolution());

			if (pExt->extract(pos++, etnicity))
				obj.setEtnicity((SmartBio::Etnicity)(etnicity));
			else
				obj.setEtnicity(defVal.etnicity());

			if (pExt->extract(pos++, sample_quality))
				obj.setSampleQuality(sample_quality);
			else
				obj.setSampleQuality(defVal.sampleQuality());

		}

	}
}