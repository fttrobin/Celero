#ifndef H_CELERO_GENERICFACTORY_H
#define H_CELERO_GENERICFACTORY_H

// www.helleboreconsulting.com

#include "celero/celero-factory.h"
#include "celero/internal/celero-export.h"

namespace celero
{
	///
	/// \class GenericFactory
	///
	/// \author	John farrier
	///
	template<class T> class GenericFactory : public Factory
	{
		public:
			///
			/// \brief	Default Constructor
			///
			GenericFactory() : Factory()
			{
			}

			///
			/// \brief	Virtual Destructor
			///
			virtual ~GenericFactory()
			{
			}

			///
			/// \brief	Overload the pure virtual base class function.
			///
			virtual std::shared_ptr<celero::IBenchmark> Create()
			{
				return std::make_shared<T>();
			}
	};
}

#endif
