#pragma once
#include <functional>
#include <string>
#include <tuple>

namespace Lab1 {

	namespace Menu {

		template <class FuncResultType, class... FuncInputTypes>
		struct MenuItem {

			using MenuItemBindedFunction = std::function<FuncResultType(FuncInputTypes...)>;

			using BindedFunctionCallbackFunction = std::function<void(FuncResultType)>;

			MenuItem(const MenuItemBindedFunction& bindedFunction, 
				const BindedFunctionCallbackFunction& callbackFunction,
				const long& itemIndex,
				const std::string& itemText,
				const std::tuple<FuncInputTypes...> bindedFunctionArgs) :
				bindedFunction(bindedFunction), 
				callbackFunction(callbackFunction),
				itemIndex(itemIndex), 
				itemText(itemText),
				bindedFunctionArgs(bindedFunctionArgs)
			{

			}

			friend std::ostream& operator<< (std::ostream& out, const MenuItem& menuItem) {
				out << menuItem.itemIndex << ". " << menuItem.itemText;
			}

			void CallBindedFunctionWithCallback() {
				callbackFunction(bindedFunction(bindedFunctionArgs));
			}

			const long& itemIndex;

			const std::string& itemText;

		private:

			const std::tuple<FuncInputTypes...> bindedFunctionArgs;

			const MenuItemBindedFunction& bindedFunction;

			const BindedFunctionCallbackFunction& callbackFunction;
		};
	}
}