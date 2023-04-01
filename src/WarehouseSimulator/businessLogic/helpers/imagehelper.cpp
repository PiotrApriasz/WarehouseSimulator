//
// Created by piotr on 01.04.2023.
//

#include <filesystem>
#include "ImageHelper.h"

const std::string ImageHelper::m_mainImagesPath = R"(..\images)";

std::string ImageHelper::getProductImagePath(Products product, Sizes size) {
    for (const auto& entry : std::filesystem::directory_iterator(m_mainImagesPath)) {
        if (entry.path().extension() == ".png") {
            auto pathLower = entry.path().string();
            auto sizeText = getSizeText(static_cast<int>(size));
            auto productText = getProductText(static_cast<int>(product));

            std::transform(pathLower.begin(),
                           pathLower.end(),
                           pathLower.begin(),
                           [](unsigned char c){
                return std::tolower(c);
            });

            std::transform(sizeText.begin(),
                           sizeText.end(),
                           sizeText.begin(),
                           [](unsigned char c){
                               return std::tolower(c);
                           });

            std::transform(productText.begin(),
                           productText.end(),
                           productText.begin(),
                           [](unsigned char c){
                               return std::tolower(c);
                           });

            auto productCheck = pathLower.find(productText) != std::string::npos;
            auto sizeCheck = pathLower.find(sizeText) != std::string::npos;

            if (productCheck && sizeCheck) {
                return entry.path().string();
            }
        }
    }

    return "";
}
