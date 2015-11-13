#include "stdafx.h"
#include "bio_personal_page.hpp"

#include "bio_resources.hpp"
#include "bio_profile_resource.hpp"
#include "bio_personal_resource.hpp"

#include "common_utils.hpp"
#include "bio_properties_utils.hpp"

#include "usettings_info_item.hpp"

namespace SmartBio
{
	namespace View
	{


		BioPersonalPage::BioPersonalPage(wxWindow* parent, wxWindowID id) : wxPanel(parent, id)
		{
			create();
			subscribe();
		}		

		BioPersonalPage::~BioPersonalPage()
		{
			unsubscribe();
		}

		void BioPersonalPage::onBtnRefreshClick(wxCommandEvent& )
		{
			wxMessageBox("Refresh");
		}

		void BioPersonalPage::onBtnFileOpenClick(wxCommandEvent& )
		{		
			wxFileDialog openFileDialog(this, "Open Image file", wxGetCwd(), "",
				                         "Image files (.bmp, .jpg, .png)|*.bmp; .jpg; *.png"
				                         , wxFD_OPEN | wxFD_FILE_MUST_EXIST);
			if (openFileDialog.ShowModal() == wxID_CANCEL)
				return;

			avatar_->loadFromFile(openFileDialog.GetPath());
			
		}
		void BioPersonalPage::onBtnSaveClick(wxCommandEvent& )
		{
			wxMessageBox("Save");
		}

		void BioPersonalPage::onBtnDeleteClick(wxCommandEvent& )
		{
			wxMessageBox("Delete");
		}

		void BioPersonalPage::onPropertyValueChanging(wxCommandEvent& evt)
		{
			wxPGValidationInfo vi;
			wxVariant st = evt.GetString();

			bool val(false); 

			wxPGProperty* pr = person_information_->GetSelectedProperty();

			if (pr != NULL)
				val = pr->ValidateValue(st, vi);


			if (val)
			{
				bool ch_all = checkValidProperties();
				if (ch_all)
				{

					if (info_bar->IsShown())
						info_bar->Hide();
					if (!btn_add_user_->IsEnabled())
						btn_add_user_->Enable();
				}
				else
				{
					if (btn_add_user_->IsEnabled())
						btn_add_user_->Disable();
				}
			
			}
			else
			{
				info_bar->ShowMessage(vi.GetFailureMessage());
				if (btn_add_user_->IsEnabled())
					btn_add_user_->Disable();
				  return;
			}					
		}

		void BioPersonalPage::do_subscribe()
		{
			btn_refresh_ ->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioPersonalPage::onBtnRefreshClick    , this);
			btn_open_		 ->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioPersonalPage::onBtnFileOpenClick   , this);
			btn_save_		 ->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioPersonalPage::onBtnSaveClick       , this);
			btn_delete_	 ->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BioPersonalPage::onBtnDeleteClick     , this);

			person_information_->Bind(wxEVT_TEXT, &BioPersonalPage::onPropertyValueChanging, this);
		}

		void BioPersonalPage::do_unsubscribe()
		{

			btn_refresh_ ->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioPersonalPage::onBtnRefreshClick    , this);
			btn_open_		 ->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioPersonalPage::onBtnFileOpenClick   , this);
			btn_save_		 ->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioPersonalPage::onBtnSaveClick       , this);
			btn_delete_	 ->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &BioPersonalPage::onBtnDeleteClick     , this);

			person_information_->Unbind(wxEVT_TEXT, &BioPersonalPage::onPropertyValueChanging, this);

		}							 

		void BioPersonalPage::do_create()
		{
			Poco::SharedPtr<BioProfileResource>  resource         (new BioProfileResource());
			Poco::SharedPtr<BioPersonalResource> personal_resource(new BioPersonalResource());

			CommonUtils utils;
			BioPropertiesUtils utils_property;

			wxBoxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);
			this->SetSizer(main_sizer);

			wxGridSizer* grid_person_sizer = new wxGridSizer(0, 3, 0, 0);

			main_sizer->Add(grid_person_sizer, 5, wxEXPAND, 5);

			wxBoxSizer* lef_person_image_sizer = new wxBoxSizer(wxVERTICAL);
			grid_person_sizer->Add(lef_person_image_sizer, 1, wxALL | wxEXPAND, 5);

			wxBoxSizer* person_image_sizer = new wxBoxSizer(wxVERTICAL);
			grid_person_sizer->Add(person_image_sizer, 1, wxALL | wxEXPAND, 5);

			wxBoxSizer* right_person_image_sizer = new wxBoxSizer(wxVERTICAL);
			grid_person_sizer->Add(right_person_image_sizer, 1, wxALL | wxEXPAND, 5);


			//TODO make in UTILS
		  avatar_ = new wxBioFaceStreamer(this, ID_AVATAR);
			person_image_sizer->Add(avatar_ , 1, wxALL | wxEXPAND, 5);
			
			person_information_ = new wxPropertyGrid( this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1)
				                                       , wxPG_TOOLBAR | wxPG_SPLITTER_AUTO_CENTER | wxPG_BOLD_MODIFIED );		
			
			first_name_    = utils_property.createProperty<wxTextPropertyEx>(ID_BIO_PERSON_FIRST_NAME
				                                                            , *person_information_   , *resource);		

			last_name_     = utils_property.createProperty<wxTextPropertyEx> (ID_BIO_PERSON_LAST_NAME    
				                                                               , *person_information_    , *resource);
			date_of_birth_ = utils_property.createProperty<wxDateProperty>( ID_BIO_PERSON_DATE_OF_BIRTH
				                                                            , *person_information_, *resource, wxPGEditor_DatePickerCtrl );

			gender_        = utils_property.createEnumPropertyWithChoises(ID_BIO_PERSON_GENDER
				                                                           , *person_information_, *personal_resource);

			country_       = utils_property.createProperty<wxTextPropertyEx> (ID_BIO_PERSON_COUNTRY
				                                                               , *person_information_, *resource);
			city_          = utils_property.createProperty<wxTextPropertyEx>(ID_BIO_PERSON_CITY
				                                                              , *person_information_, *resource);
			email_         = utils_property.createProperty<wxEmailPropertyEx>(ID_BIO_PERSON_EMAIL
				                                                               , *person_information_, *resource);
			comments_			 = utils_property.createProperty<wxStringProperty> (ID_BIO_PERSON_COMMENTS
				                                                               , *person_information_, *resource);
		  rights_        = utils_property.createEnumPropertyWithChoises(ID_BIO_PERSON_RIGTS
				                                                           , *person_information_, *personal_resource);

			properties_.insert(std::pair<std::string, int>(first_name_->GetName().ToStdString(), ID_BIO_PERSON_FIRST_NAME));
			properties_.insert(std::pair<std::string, int>(last_name_ ->GetName().ToStdString(), ID_BIO_PERSON_LAST_NAME) );
			properties_.insert(std::pair<std::string, int>(country_   ->GetName().ToStdString(), ID_BIO_PERSON_COUNTRY)   );
			properties_.insert(std::pair<std::string, int>(city_      ->GetName().ToStdString(), ID_BIO_PERSON_CITY)      );
			properties_.insert(std::pair<std::string, int>(email_     ->GetName().ToStdString(), ID_BIO_PERSON_EMAIL)     );
			
			// ^[a-zA-Z0-9_\.]+@[a-zA-Z_]+?\.[a-zA-Z]{2,63}$   email
			//  ^[a-zA-Z`\-]{2,}$ Name
			// ^[0-9]{2,2}$  Age
			/********************************************************************************/

			wxBoxSizer* sizer_personal_properties = new wxBoxSizer(wxHORIZONTAL);
			main_sizer->Add(sizer_personal_properties, 5, wxALL | wxEXPAND, 5);

			wxBoxSizer* sizer_porperty_grid = new wxBoxSizer(wxVERTICAL);
			sizer_personal_properties->Add(sizer_porperty_grid, 7, wxEXPAND, 5);

			info_bar = new wxInfoBar(this, wxID_ANY);
			info_bar->SetSize(wxSize(-1, -1));			

			sizer_porperty_grid->Add(info_bar, 0, wxALL | wxEXPAND, 5);

			sizer_porperty_grid->Add(person_information_, 7, wxEXPAND, 5);
			
			wxBoxSizer* sizer_tools = new wxBoxSizer(wxVERTICAL);
			sizer_personal_properties->Add(sizer_tools, 0, wxALIGN_RIGHT, 5);
																																																															 
			btn_add_user_   = utils.addButton(ID_BTN_PROFILE_ADD_USER , this, *resource, sizer_tools, wxALIGN_TOP);
			btn_open_		    = utils.addButton(ID_BTN_OPEN             , this, *resource, sizer_tools, wxALIGN_TOP);
			btn_refresh_		= utils.addButton(ID_BTN_REFRESH          , this, *resource, sizer_tools, wxALIGN_TOP);
			btn_save_		    = utils.addButton(ID_BTN_SAVE             , this, *resource, sizer_tools, wxALIGN_TOP);
			btn_delete_     = utils.addButton(ID_BTN_DELETE           , this, *resource, sizer_tools, wxALIGN_TOP);

			btn_add_user_->Disable();

			/*************************************************************************************/	

			this->Layout();
		}		

	  void BioPersonalPage::update(const Data::BioPerson& person)
		{
			first_name_   ->SetValue(person.firstName());
			last_name_    ->SetValue(person.lastName() );
			date_of_birth_->SetValue(wxDateTime::Now() ); //person.dateOfBirth
			gender_       ->SetValue(person.gender()   );
			city_         ->SetValue(person.city()     );
			country_      ->SetValue(person.country()  );
			email_        ->SetValue(person.email()    );
			comments_     ->SetValue(person.comments() );
			rights_       ->SetValue(person.rights()   );

			btn_add_user_->Hide();
		}

		void BioPersonalPage::update(bool /*default_update*/ )
		{

			//TODO transfer to resources
		

			btn_add_user_->Disable();
			info_bar->ShowMessage("Please fill all required fields");

			btn_refresh_->Hide();
			btn_save_   ->Hide();
			btn_delete_ ->Hide();

		}

		Data::BioPerson& BioPersonalPage::getEditablePerson()
		{
			editable_person_.setFirstName   (first_name_   ->GetValue());
			editable_person_.setLastName    (last_name_    ->GetValue());

			Poco::DateTime time_temp;
			int timezone;
			Poco::DateTimeParser::parse( Poco::DateTimeFormat::SORTABLE_FORMAT
				                         , date_of_birth_->GetValue().GetString().ToStdString()
																 , time_temp, timezone);

			editable_person_.setDateOfBirth (time_temp                                              );
			editable_person_.setGender      ((SmartBio::Data::Gender)(gender_->GetValue().GetLong()));
			editable_person_.setCity        (city_         ->GetValue()                             );
			editable_person_.setCountry     (country_      ->GetValue()                             );
			editable_person_.setEmail       (email_        ->GetValue()                             );
			editable_person_.setComments    (comments_     ->GetValue()                             ); 			
			editable_person_.setRights      ((SmartBio::Data::Rights)(rights_->GetValue().GetLong()));
			
			return editable_person_;
		}


		/*void BioPersonalPage::addUserToDataBase()
		{

			for (auto id = properties_.begin(); id != properties_.end(); ++id)
			{
				bool res = false;
				wxPGProperty* name = person_information_->GetPropertyByName(id->first);
			}

			//db_io->write<BioSubject, BioSubjectTable>(p);
		}*/

		bool BioPersonalPage::checkValidProperties()
		{
			bool val(false);
			wxPGValidationInfo vi;
			for (auto ptr = properties_.begin(); ptr != properties_.end(); ++ptr)
			{
				wxPGProperty* prop = person_information_->GetPropertyByName(ptr->first);
				if (prop != NULL)
				{
					wxVariant value = prop->GetValue();
					val = prop->ValidateValue(value, vi);
					if (!val)
						return val;
				}
			}
			return val;
		}


	}
}