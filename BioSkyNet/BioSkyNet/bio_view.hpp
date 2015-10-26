#pragma once

#ifndef View_INCLUDED
#define View_INCLUDED



//#include "../SmartBioModel/bio_model.hpp"
#include "../SmartInterfaces/iview.hpp"

//#include "tab_controller.hpp"
#include "bio_form.hpp"



//using namespace SmartBio::Model;
namespace SmartBio { namespace View 
{
	class BioView : public Interfaces::IView
		            , public Interfaces::UncopyableSingletonWithParam<BioView, Interfaces::IModel>
	{		
		friend class Interfaces::IView;
		friend class Interfaces::UncopyableSingletonWithParam<BioView, Interfaces::IModel>;

	public:		
		virtual ~BioView();		

		BioForm const& getForm() const;

		
		void setTopWindow( wxApp& application )
		{
			bio_form_->setTop( application );
		}
		
	protected:
		BioView(Poco::SharedPtr<Interfaces::IModel>& model);

	private:
		//BioApplication* bio_application;
		BioForm*  bio_form_;
	/*	Poco::SharedPtr<TabController> tab_control_;
		Poco::SharedPtr<LogControl>    log_control_;*/
		void subscribe();



	private:
		//std::vector<TabPage*> tab_pages_;

	private:			

		 
		void do_initialize() final;


	};

} }


#endif