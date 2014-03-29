#ifndef H_CELERO_PRINT_H
#define H_CELERO_PRINT_H
 
// www.helleboreconsulting.com

#include <string>
#include <memory>
 
namespace celero
{
	class IBenchmarkInfo;

	///
	/// \namespace print
	///
	/// \author	John farrier
	///
	namespace print
	{
		void StageBanner(const std::string& x);
		void GreenBar(const std::string& x);
		void Run(std::shared_ptr<IBenchmarkInfo> x);
		void Auto(std::shared_ptr<IBenchmarkInfo> x);
		void Done(std::shared_ptr<IBenchmarkInfo> x);
		void Baseline(std::shared_ptr<IBenchmarkInfo> x);
	}
}

#endif
