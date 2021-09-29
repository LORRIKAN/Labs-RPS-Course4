#pragma once
#include <functional>
#include <string>

namespace Lab1 {

	namespace Menu {

		template <class FuncResultType, class... FuncInputTypes>
		class MenuItem {

		};

		template <class FuncResultType, class... FuncInputTypes>
		class MenuItem<FuncResultType(FuncInputTypes...)> {
		public:
			MenuItem(const std::function<FuncResultType(FuncInputTypes)>& bindedFunction,
				const long& bindedFunction, const std::string& bindedFunction) :
				bindedFunction(bindedFunction), itemIndex(itemIndex), itemText(itemText)
			{

			}

			friend std::ostream& operator<< (std::ostream& out, const MenuItem& menuItem) {
				out << menuItem.itemIndex << ". " << menuItem.itemText;
			}

			const std::function<FuncRetType(FuncInputTypes)>& bindedFunction;

			const long& itemIndex;

			const std::string& itemText;
		};
	}
}