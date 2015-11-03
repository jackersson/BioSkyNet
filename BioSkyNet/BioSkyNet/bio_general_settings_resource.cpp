#include "stdafx.h"
#include "bio_general_settings_resource.hpp"

#include "bio_resources.hpp"

namespace SmartBio
{
	namespace View
	{
		
		BioGeneralSettingsResource::BioGeneralSettingsResource()
		{
			initialize();
		}

		BioGeneralSettingsResource::~BioGeneralSettingsResource()	{}


		void BioGeneralSettingsResource::do_initialize()
		{
		
			std::string pr_matching_threshold          = "Matching threshold";
			std::string pr_matching_threshold_value    = "Matching.Threshold";
			std::string pr_matching_threshold_hint     = "Threshold that separates identical from different templates.";
																							   
			std::string pr_maximal_result_count        = "Maximal result count";
			std::string pr_maximal_result_count_value  = "Matching.MaximalResultCount";
			std::string pr_maximal_result_count_hint   = "Maximum number of matching results returned";

			std::string pr_matching_with_details       = "Matching with details";
			std::string pr_matching_with_details_value = "Matching.MatchingWithDetails";
			std::string pr_matching_with_details_hint  = "if checked, additional details will be returned with matching result";

			std::string pr_first_result_only           = "First result only";
			std::string pr_first_result_only_value     = "Matching.FirstResultOnly";
			std::string pr_first_result_only_hint      = "if checked, only the first positive result will be returned during identification";

		
			View::USettingInfoItem matching_threshold( pr_matching_threshold, ""
				                                       , pr_matching_threshold_hint, "", ""
																							 , pr_first_result_only_value );

			View::USettingInfoItem maximal_result_count( pr_maximal_result_count, ""
				                                         , pr_maximal_result_count_hint, "", ""
				                                         , pr_maximal_result_count_value);

			View::USettingInfoItem matching_with_details( pr_matching_with_details, ""
				                                          , pr_matching_with_details_hint, "", ""
				                                          , pr_matching_with_details_value);

			View::USettingInfoItem first_result_only(  pr_first_result_only, ""
				                                       , pr_first_result_only_hint, "", ""
				                                       , pr_first_result_only_value);

			
			insert(UIBioSettings::ID_MATCHING_THRESHOLD        , matching_threshold   );
			insert(UIBioSettings::ID_MAXIMAL_RESULT_COUNT      , maximal_result_count );
			insert(UIBioSettings::ID_RETURN_MATCHING_DETAILS   , matching_with_details);
			insert(UIBioSettings::ID_MATCHING_FIRST_RESULT_ONLY, first_result_only    );


		}

	}
}


