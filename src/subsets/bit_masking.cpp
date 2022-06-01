#include "assignment/subsets/bit_masking.hpp"

#include <cassert>  // assert

#include "assignment/bits.hpp"  // is_bit_set

namespace assignment {

  std::vector<std::vector<int>> SubsetsBitMasking::generate(const std::vector<int>& set) const {
    assert(set.size() <= 16);

    const auto num_elems = static_cast<int>(set.size());  // N
    const int num_subsets = 1 << num_elems;               // 2^N

    // выделяем память
    auto subsets = std::vector<std::vector<int>>(num_subsets);

    // 1. Внешний цикл: пробегаемся по всем битовым маскам от 0..00 до 1..11
    for (int mask = 0; mask < num_subsets; mask++)  {
//      std::vector<int> curr_subset;
      for (int pos = 0; pos < num_elems; pos++) {
        if (is_bit_set(mask, pos)) {
          // добавить элемент в текущее подмножество
//          curr_subset.push_back();
          subsets[mask].push_back(pos);
        }
      }
//      subsets.push_back(curr_subset);
    }
    // 2. Внутренний цикл: проверка разрядов битовой маски и генерация подмножества, ассоциирующегося с этой маской
    // Tips: для проверки разряда бита на 1 (единицу) используйте функцию is_bit_set

    return subsets;
  }

}  // namespace assignment