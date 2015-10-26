#ifndef IFactory_INCLUDED
#define IFactory_INCLUDED

//#include <list>


namespace SmartBio { namespace Interfaces 
{

	template <typename InstanceType>
	class IFactory 
	{

	public:		
	 

	private:		
	  virtual InstanceType create() = 0;



	};

} }

#endif
