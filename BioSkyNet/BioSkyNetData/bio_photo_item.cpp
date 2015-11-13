#include "stdafx.h"
#include "bio_photo_item.hpp"

namespace SmartBio
{
	namespace Data
	{
		BioPhotoItem::BioPhotoItem() : photo_path_         ("")
			                           , fir_path_					 ("")
			                           , natural_skin_color_ (true)
			                           , gender_						 (Gender::Male)
			                           , age_							 	 (10)
			                           , glasses_					 	 (true)
			                           , resolution_				 ("")
																 , etnicity_           (Etnicity::White)
																 , sample_quality_     (0.0)
																 
		{

		}
		BioPhotoItem::BioPhotoItem(int index
			, const std::string& photo_path
			, const std::string& fir_path
			, bool               natural_skin_color
			, Gender             gender
			, int                age
			, bool               glasses
			, const std::string& resolution
			, Etnicity					 etnicity    
			, float              sample_quality    )
			


			: index_               ( index              )
			, photo_path_          ( photo_path         )
			, fir_path_						 ( fir_path						)
			, natural_skin_color_	 ( natural_skin_color	)
			, gender_							 ( gender							)
			, age_								 ( age								)
			, glasses_						 ( glasses						)
			, resolution_					 ( resolution					)
			, etnicity_						 ( etnicity           )
			, sample_quality_      (sample_quality      )
		{

		}

		BioPhotoItem::~BioPhotoItem() {}


		int BioPhotoItem::index() const
		{
			return index_;
		}

		const std::string& BioPhotoItem::photoPath() const
		{
			return photo_path_;
		}

		const std::string& BioPhotoItem::firPath() const
		{
			return fir_path_;
		}

		bool BioPhotoItem::naturalSkinColor() const
		{
			return natural_skin_color_;
		}

		Gender BioPhotoItem::gender() const
		{
			return gender_;
		}

		int BioPhotoItem::age() const
		{
			return age_;
		}

		bool BioPhotoItem::glasses() const
		{
			return glasses_;
		}

		const std::string& BioPhotoItem::resolution() const
		{
			return resolution_;
		}

		Etnicity BioPhotoItem::etnicity() const
		{
			return etnicity_;
		}

		float BioPhotoItem::sampleQuality() const
		{
			return sample_quality_;
		}

		void BioPhotoItem::setIndex(int index)
		{
			index_ = index;
		}

		void BioPhotoItem::setPhotoPath(const std::string& photo_path)
		{
			photo_path_ = photo_path;
		}

		void BioPhotoItem::setFirPath(const std::string& fir_path)
		{
			fir_path_ = fir_path;
		}

		void BioPhotoItem::setNaturalSkinColor(bool natural_skin_color)
		{
			natural_skin_color_ = natural_skin_color;
		}

		void BioPhotoItem::setGender(Gender gender)
		{
			gender_ = gender;
		}

		void BioPhotoItem::setAge(int age)
		{
			age_ = age;
		}

		void BioPhotoItem::setGlasses(bool glasses)
		{
			glasses_ = glasses;
		}

		void BioPhotoItem::setResolution(const std::string& resolution)
		{
			resolution_ = resolution;
		}

		void BioPhotoItem::setEtnicity(Etnicity etnicity)
		{
			etnicity_ = etnicity;
		}

		void BioPhotoItem::setSampleQuality(float sample_quality)
		{
			sample_quality_ = sample_quality;
		}
		
	}
}