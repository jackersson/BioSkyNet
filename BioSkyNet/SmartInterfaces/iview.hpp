#ifndef IView_INCLUDED
#define IView_INCLUDED

#include "imodel.hpp"
#include "patterns.hpp"


namespace SmartBio { namespace Interfaces 
{	
	
	class IView : private Uncopyable
	{		
	public:
		virtual ~IView() {};
		
		void initialize()
		{
			do_initialize();
		}

	protected:		
		Poco::SharedPtr<IModel> model_;
	  IView( Poco::SharedPtr<IModel>& model ) {
			model_ = model;
		};

	private:		
		bool initialized_;
		virtual void do_initialize() = 0;

	};

} }

#endif


