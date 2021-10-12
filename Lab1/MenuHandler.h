#pragma once
#include <variant>
#include "MenuItem.h"

namespace Lab1 {

	namespace Menu {

		template <class... MenuItemsBindedFunctionsArgs>
		class MenuHandler {

			MenuHandler(std::variant<MenuItem<MenuItemsBindedFunctionsArgs...>> menuItems)
			{

			}
		};
	}
}