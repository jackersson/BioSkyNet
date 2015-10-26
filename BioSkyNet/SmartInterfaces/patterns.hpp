#ifndef Patterns_INCLUDED
#define Patterns_INCLUDED

//#include <Poco/SingletonHolder.h>
#include "Poco/SharedPtr.h"

namespace SmartBio { namespace Interfaces 
{
	
	class Uncopyable
	{	
	protected:

		Uncopyable() {};
		~Uncopyable() {};
		
	private:	
		Uncopyable (const Uncopyable&);	
		Uncopyable& operator=(const Uncopyable&);	

	};


	//thread-safe singleton
	template <typename ClassType>
	class Singleton
	{	
	public:

		Singleton() {};
		~Singleton() {};

		static ClassType& instance()
		{
			static Poco::SingletonHolder<ClassType> instance_;
			return (*instance_).get();
		}	

	};


	//no thread-safe uncopyable singleton 
	template <typename ClassType>
	class UncopyableSingleton : private Uncopyable
	{	
	public:		
	
		static Poco::SharedPtr<ClassType> instance()
		{			
			static Poco::SharedPtr<ClassType> instance_( new ClassType() ) ;				
			return instance_;
		}

	protected:		
		UncopyableSingleton(){};
		~UncopyableSingleton() {};
	};
	
	//with poco
	template <typename ClassType, typename ParametrType>
	class UncopyableSingletonWithParam : private Uncopyable
	{			
	public:
		static Poco::SharedPtr<ClassType> instance( Poco::SharedPtr<ParametrType> t )
		{
			static Poco::SharedPtr<ClassType> instance_( new ClassType( t ) );		
			return instance_;
		}

	protected:
		UncopyableSingletonWithParam(){};
		~UncopyableSingletonWithParam() {};

	};

	template <typename ClassType, typename ParametrType>
	class UncopyableSingletonWithParamType : private Uncopyable
	{			
	public:
		static Poco::SharedPtr<ClassType> instance( ParametrType t )
		{
			static Poco::SharedPtr<ClassType> instance_( new ClassType( t ) );		
			return instance_;
		}

	protected:
		UncopyableSingletonWithParamType(){};
		~UncopyableSingletonWithParamType() {};

	};



} }

#endif
