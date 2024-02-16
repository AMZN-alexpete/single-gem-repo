
#pragma once

namespace single_gem_repo
{
    // System Component TypeIds
    inline constexpr const char* single_gem_repoSystemComponentTypeId = "{B00470EF-E80B-46B5-9B85-EAEEAF269B3B}";
    inline constexpr const char* single_gem_repoEditorSystemComponentTypeId = "{CF732E5A-1431-4D89-8665-B28D583E7D44}";

    // Module derived classes TypeIds
    inline constexpr const char* single_gem_repoModuleInterfaceTypeId = "{E3A6EBCF-6704-4A55-8709-870F797B2566}";
    inline constexpr const char* single_gem_repoModuleTypeId = "{18194819-8CF3-4600-A8F8-66ED5C14BE8A}";
    // The Editor Module by default is mutually exclusive with the Client Module
    // so they use the Same TypeId
    inline constexpr const char* single_gem_repoEditorModuleTypeId = single_gem_repoModuleTypeId;

    // Interface TypeIds
    inline constexpr const char* single_gem_repoRequestsTypeId = "{22C8166A-E747-4F3E-8680-5E1D10F82589}";
} // namespace single_gem_repo
