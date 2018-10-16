//flxg{e9337ce221912ea7e481b3d9a630564e}
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <dlfcn.h>
#include <gmp.h>

#include "jh.h"

const unsigned char w[] = {
32, 41, 166, 139, 203, 32, 43, 157, 191, 12, 213, 79, 236, 169, 70, 14, 152, 150, 33, 163, 6, 181, 104, 222, 81, 28, 160, 251, 101, 153, 16, 55, 137, 165, 64, 41, 88, 191, 82, 241, 192, 46, 97, 74, 65, 175, 214, 12, 172, 68, 189, 26, 17, 224, 182, 230, 202, 163, 82, 95, 162, 120, 238, 9, 218, 94, 69, 147, 176, 41, 170, 58, 82, 253, 125, 145, 185, 215, 3, 213, 193, 53, 131, 199, 148, 83, 105, 103, 177, 196, 125, 17, 33, 254, 80, 191, 188, 225, 51, 175, 199, 101, 233, 27, 52, 143, 66, 79, 236, 251, 83, 6, 39, 106, 72, 188, 23, 11, 52, 22, 10, 40, 128, 50, 213, 253, 93, 171, 86, 63, 143, 111, 20, 60, 56, 141, 200, 137, 95, 208, 1, 49, 170, 192, 215, 25, 104, 163, 94, 6, 183, 185, 103, 4, 116, 71, 229, 101, 12, 30, 115, 150, 246, 85, 95, 25, 157, 39, 189, 242, 8, 209, 139, 43, 46, 226, 67, 21, 185, 170, 248, 37, 255, 233, 198, 152, 138, 158, 240, 21, 199, 220, 25, 89, 126, 24, 245, 132, 105, 128, 108, 226, 29, 58, 164, 89, 20, 138, 173, 203, 15, 3, 225, 157, 23, 44, 169, 84, 111, 50, 3, 54, 223, 157, 164, 136, 102, 142, 59, 104, 0, 218, 155, 76, 239, 144, 189, 182, 81, 92, 103, 127, 139, 202, 250, 83, 65, 171, 117, 180, 83, 95, 238, 61, 133, 57, 13, 218, 117, 121, 244, 121, 161, 200, 240, 64, 247, 24, 220, 98, 54, 48, 136, 254, 204, 177, 117, 82, 187, 17, 83, 93, 24, 49, 6, 34, 245, 192, 34, 146, 3, 136, 223, 221, 94, 147, 132, 214, 218, 198, 82, 31, 95, 144, 12, 107, 12, 84, 68, 241, 114, 56, 173, 103, 217, 45, 159, 60, 194, 102, 98, 61, 1, 143, 130, 23, 51, 57, 127, 42, 179, 187, 194, 19, 88, 137, 7, 165, 29, 104, 150, 21, 13, 44, 55, 208, 67, 75, 85, 43, 240, 108, 161, 197, 177, 193, 72, 68, 13, 11, 99, 128, 183, 66, 74, 158, 56, 245, 128, 242, 74, 183, 118, 132, 222, 230, 63, 209, 230, 1, 204, 252, 138, 204, 128, 150, 62, 0, 41, 212, 87, 115, 52, 246, 247, 216, 169, 149, 49, 73, 113, 209, 119, 145, 193, 129, 19, 108, 59, 140, 39, 186, 208, 10, 143, 218, 237, 228, 244, 229, 84, 129, 62, 153, 108, 144, 111, 237, 172, 180, 107, 99, 5, 251, 33, 104, 185, 194, 128, 192, 156, 140, 54, 62, 45, 116, 234, 71, 195, 242, 175, 169, 123, 41, 127, 7, 211, 54, 86, 119, 210, 75, 242, 42, 221, 96, 236, 37, 247, 94, 68, 145, 122, 20, 247, 192, 102, 195, 222, 72, 106, 59, 27, 79, 208, 221, 49, 75, 194, 166, 162, 234, 163, 191, 125, 234, 7, 5, 90, 152, 1, 68, 182, 56, 183, 72, 88, 121, 232, 242, 157, 31, 242, 35, 225, 49, 106, 133, 130, 10, 97, 0, 207, 172, 8, 167, 18, 13, 101, 0, 184, 72, 26, 48, 241, 62, 223, 12, 55, 131, 191, 164, 146, 37, 106, 24, 64, 70, 192, 55, 24, 18, 143, 173, 156, 169, 229, 144, 40, 104, 16, 95, 244, 91, 45, 191, 82, 55, 96, 171, 237, 49, 212, 226, 169, 150, 38, 248, 165, 135, 177, 164, 160, 227, 85, 63, 173, 84, 238, 176, 94, 93, 109, 88, 34, 30, 150, 241, 88, 250, 11, 161, 72, 186, 92, 250, 105, 224, 16, 101, 67, 132, 69, 163, 159, 216, 41, 182, 227, 172, 214, 27, 193, 75, 186, 231, 109, 54, 79, 88, 56, 47, 27, 130, 176, 127, 142, 16, 209, 199, 56, 124, 238, 230, 1, 248, 72, 120, 123, 198, 36, 0, 109, 81, 151, 73, 145, 243, 30, 46, 146, 110, 21, 146, 115, 244, 71, 234, 51, 166, 193, 223, 31, 242, 208, 37, 25, 32, 44, 145, 55, 38, 138, 67, 43, 81, 152, 111, 211, 50, 11, 179, 101, 83, 104, 128, 82, 126, 18, 41, 106, 48, 135, 150, 110, 92, 65, 2, 212, 126, 51, 66, 9, 152, 119, 147, 194, 74, 80, 144, 221, 1, 92, 45, 131, 120, 88, 103, 116, 38, 243, 168, 215, 114, 211, 96, 232, 88, 39, 169, 184, 148, 217, 42, 120, 169, 4, 114, 235, 107, 209, 174, 204, 77, 193, 30, 233, 207, 191, 177, 73, 45, 173, 143, 35, 236, 152, 185, 176, 0, 146, 157, 113, 210, 131, 122, 204, 36, 145, 109, 197, 191, 45, 5, 55, 209, 114, 89, 250, 68, 113, 149, 76, 166, 165, 216, 208, 190, 213, 229, 248, 13, 193, 23, 21, 59, 43, 127, 188, 193, 250, 199, 243, 155, 196, 153, 251, 14, 201, 50, 3, 181, 33, 124, 47, 26, 72, 52, 185, 138, 154, 204, 125, 90, 91, 63, 18, 46, 117, 157, 1, 240, 101, 75, 53, 70, 89, 36, 235, 220, 234, 230, 165, 204, 250, 71, 223, 105, 22, 143, 199, 212, 4, 2, 156, 42, 24, 101, 14, 135, 56, 172, 123, 48, 223, 38, 191, 51, 35, 31, 156, 130, 40, 189, 152, 94, 69, 217, 156, 106, 237, 234, 174, 138, 153, 182, 252, 192, 20, 18, 45, 96, 230, 134, 110, 154, 238, 202, 125, 100, 162, 224, 125, 65, 59, 81, 74, 97, 80, 246, 234, 207, 25, 14, 190, 154, 205, 41, 253, 84, 224, 239, 44, 16, 11, 96, 85, 230, 141, 175, 133, 209, 64, 162, 124, 59, 32, 204, 10, 122, 42, 188, 30, 61, 192, 41, 222, 18, 211, 181, 243, 99, 180, 212, 74, 159, 197, 112, 209, 43, 93, 46, 199, 57, 215, 32, 94, 132, 19, 235, 210, 75, 208, 165, 94, 208, 12, 241, 217, 33, 159, 6, 244, 199, 83, 224, 155, 31, 245, 26, 88, 153, 13, 17, 37, 162, 68, 146, 87, 157, 37, 88, 30, 85, 29, 92, 118, 14, 13, 170, 19, 210, 234, 57, 115, 158, 121, 59, 14, 67, 39, 163, 69, 95, 100, 13, 81, 255, 64, 133, 92, 23, 172, 22, 252, 108, 199, 88, 133, 34, 123, 152, 43, 187, 216, 221, 36, 59, 110, 51, 51, 35, 51, 223, 58, 239, 113, 151, 14, 96, 122, 111, 222, 228, 29, 146, 47, 204, 69, 6, 141, 152, 193, 191, 156, 88, 223, 74, 56, 216, 32, 63, 159, 74, 78, 184, 105, 39, 53, 165, 211, 130, 131, 231, 182, 44, 48, 107, 244, 85, 87, 96, 103, 48, 41, 55, 180, 122, 150, 17, 81, 108, 238, 57, 137, 38, 146, 73, 79, 164, 239, 102, 209, 76, 132, 252, 242, 28, 93, 154, 167, 38, 120, 96, 200, 87, 33, 210, 143, 204, 206, 149, 197, 43, 117, 174, 31, 139, 177, 99, 111, 49, 180, 191, 170, 50, 156, 74, 16, 143, 212, 158, 48, 27, 32, 239, 240, 3, 169, 104, 150, 149, 76, 254, 28, 89, 34, 19, 54, 146, 73, 152, 92, 172, 132, 10, 70, 244, 52, 88, 81, 237, 52, 16, 201, 168, 198, 32, 229, 47, 78, 156, 23, 188, 62, 119, 60, 211, 134, 54, 113, 255, 245, 127, 57, 168, 107, 62, 90, 103, 14, 76, 36, 42, 96, 245, 42, 218, 230, 101, 236, 32, 98, 50, 161, 219, 63, 148, 33, 45, 65, 151, 229, 34, 19, 186, 147, 129, 225, 115, 58, 209, 118, 10, 236, 202, 98, 222, 38, 245, 158, 204, 182, 229, 148, 166, 253, 236, 195, 75, 249, 20, 135, 2, 193, 43, 190, 135, 222, 233, 51, 54, 30, 136, 247, 196, 21, 105, 247, 187, 80, 155, 27, 151, 109, 200, 144, 220, 42, 134, 164, 211, 51, 8, 87, 14, 133, 146, 136, 79, 78, 130, 132, 150, 91, 218, 69, 74, 176, 154, 161, 85, 46, 34, 129, 8, 86, 117, 85, 85, 142, 85, 117, 232, 166, 55, 161, 186, 158, 83, 121, 128, 77, 153, 28, 82, 92, 22, 145, 160, 143, 168, 57, 122, 97, 86, 181, 11, 72, 249, 47, 5, 79, 18, 195, 252, 186, 198, 179, 186, 68, 189, 70, 208, 99, 124, 151, 194, 207, 27, 13, 6, 61, 142, 90, 51, 5, 155, 201, 95, 104, 215, 99, 16, 235, 203, 74, 49, 200, 231, 117, 238, 162, 204, 238, 23, 60, 220, 123, 38, 101, 143, 45, 255, 138, 130, 173, 78, 34, 88, 154, 20, 124, 174, 65, 99, 2, 72, 206, 73, 182, 78, 161, 114, 100, 156, 221, 73, 245, 145, 75, 248, 99, 39, 23, 222, 132, 53, 169, 26, 116, 65, 118, 136, 166, 60, 161, 34, 60, 3, 147, 72, 107, 135, 64, 235, 136, 100, 105, 84, 203, 249, 60, 160, 200, 56, 237, 199, 254, 59, 7, 179, 164, 226, 82, 43, 10, 208, 222, 183, 111, 221, 116, 237, 132, 50, 235, 55, 188, 99, 152, 128, 34, 126, 10, 122, 22, 56, 247, 64, 160, 105, 20, 47, 55, 167, 230, 6, 116, 65, 202, 235, 174, 85, 126, 4, 52, 247, 97, 90, 242, 3, 184, 88, 104, 193, 177, 174, 51, 194, 206, 148, 157, 95, 47, 25, 250, 5, 145, 246, 169, 67, 56, 224, 207, 122, 25, 234, 205, 77, 209, 39, 85, 130, 188, 249, 240, 236, 36, 91, 48, 245, 101, 224, 5, 21, 43, 66, 206, 219, 67, 223, 36, 79, 100, 53, 201, 103, 148, 205, 31, 23, 77, 71, 142, 83, 215, 164, 127, 121, 87, 57, 100, 159, 203, 12, 114, 128, 10, 238, 24, 12, 48, 200, 197, 237, 158, 43, 105, 144, 73, 15, 113, 243, 98, 196, 115, 68, 235, 97, 81, 201, 31, 80, 153, 229, 236, 243, 55, 93, 7, 0, 18, 241, 96, 135, 133, 77, 106, 208, 182, 194, 29, 18, 97, 238, 178, 232, 65, 128, 205, 184, 115, 50, 75, 11, 1, 63, 59, 179, 57, 189, 180, 132, 22, 180, 116, 50, 200, 168, 160, 0, 123, 89, 55, 222, 51, 150, 159, 226, 93, 88, 233, 97, 102, 155, 113, 202, 101, 8, 121, 32, 46, 88, 185, 6, 26, 131, 238, 40, 244, 80, 175, 224, 195, 136, 254, 81, 211, 131, 0, 249, 69, 108, 137, 247, 140, 151, 88, 68, 194, 227, 6, 61, 59, 175, 99, 151, 240, 151, 15, 52, 52, 177, 218, 227, 16, 13, 243, 118, 121, 95, 35, 125, 59, 52, 42, 91, 175, 116, 5, 168, 196, 209, 197, 108, 80, 105, 60, 98, 204, 10, 210, 153, 90, 11, 183, 194, 51, 23, 1, 33, 216, 217, 219, 248, 195, 202, 77, 180, 22, 120, 159, 80, 214, 15, 99, 218, 11, 25, 15, 88, 68, 16, 27, 88, 19, 144, 69, 33, 38, 3, 10, 53, 227, 148, 212, 158, 178, 124, 71, 137, 185, 56, 52, 237, 159, 53, 250, 15, 49, 238, 254, 137, 227, 100, 159, 215, 252, 129, 27, 245, 254, 220, 182, 209, 180, 227, 90, 141, 9, 166, 199, 53, 31, 4, 240, 18, 188, 141, 238, 186, 221, 52, 116, 62, 229, 208, 62, 136, 66, 39, 38, 172, 241, 250, 110, 53, 180, 241, 7, 84, 52, 83, 130, 55, 102, 118, 233, 152, 135, 101, 161, 108, 158, 96, 250, 21, 95, 182, 179, 74, 122, 49, 208, 129, 184, 12, 159, 116, 30, 212, 133, 74, 108, 213, 122, 217, 18, 97, 95, 156, 236, 239, 162, 73, 182, 120, 6, 1, 168, 97, 85, 112, 182, 123, 75, 170, 120, 255, 93, 19, 40, 158, 223, 146, 205, 137, 182, 68, 53, 233, 144, 125, 135, 116, 251, 53, 150, 37, 190, 211, 19, 36, 49, 54, 134, 165, 168, 15, 65, 181, 200, 112, 93, 23, 200, 154, 251, 110, 140, 220, 86, 170, 53, 253, 215, 119, 222, 213, 50, 172, 169, 73, 148, 178, 106, 40, 203, 144, 176, 159, 211, 18, 83, 160, 2, 104, 247, 127, 232, 200, 36, 142, 227, 51, 103, 30, 155, 198, 174, 240, 7, 168, 183, 167, 87, 165, 68, 111, 157, 231, 19, 116, 193, 3, 234, 98, 220, 255, 92, 76, 5, 160, 107, 245, 180, 168, 112, 65, 25, 2, 86, 114, 27, 144, 5, 111, 214, 30, 92, 253, 241, 181, 134, 83, 172, 94, 235, 241, 143, 117, 33, 130, 98, 55, 86, 238, 203, 89, 107, 10, 36, 6, 153, 124, 105, 130, 15, 93, 8, 182, 194, 188, 135, 247, 73, 150, 12, 4, 92, 195, 2, 46, 187, 130, 155, 234, 241, 70, 150, 144, 161, 1, 1, 76, 98, 223, 90, 24, 246, 223, 217, 97, 7, 161, 61, 135, 82, 95, 109, 207, 253, 182, 72, 50, 159, 240, 106, 102, 129, 218, 47, 15, 241, 94, 149, 89, 55, 177, 97, 64, 79, 124, 157, 92, 145, 143, 6, 176, 247, 42, 11, 74, 196, 152, 206, 147, 156, 148, 241, 108, 89, 225, 201, 219, 236, 193, 42, 62, 227, 115, 216, 22, 64, 61, 110, 100, 163, 234, 36, 37, 251, 148, 31, 50, 79, 175, 91, 126, 222, 207, 179, 112, 204, 8, 195, 90, 87, 145, 149, 140, 61, 237, 198, 90, 87, 174, 134, 250, 213, 71, 211, 2, 227, 149, 213, 76, 47, 193, 104, 253, 112, 77, 252, 91, 69, 246, 11, 178, 8, 172, 101, 39, 100, 223, 71, 212, 39, 166, 0, 118, 132, 168, 52, 219, 58, 109, 141, 69, 21, 127, 141, 15, 62, 19, 224, 127, 117, 172, 126, 130, 222, 97, 207, 169, 220, 121, 68, 217, 11, 132, 191, 97, 226, 85, 117, 168, 17, 34, 199, 210, 2, 62, 12, 131, 242, 25, 124, 1, 228, 21, 205, 117, 202, 43, 237, 215, 56, 194, 199, 124, 92, 167, 200, 113, 255, 201, 160, 174, 252, 119, 32, 0, 17, 125, 143, 41, 41, 182, 177, 142, 202, 71, 215, 182, 18, 112, 117, 169, 193, 233, 160, 228, 126, 187, 251, 178, 70, 93, 133, 0, 144, 101, 122, 48, 14, 51, 173, 198, 82, 195, 30, 228, 131, 132, 42, 199, 230, 63, 28, 166, 254, 160, 23, 86, 153, 219, 8, 56, 245, 81, 136, 108, 145, 202, 35, 235, 17, 237, 31, 7, 54, 131, 134, 184, 106, 222, 85, 13, 136, 114, 143, 237, 199, 244, 213, 229, 217, 68, 161, 151, 210, 120, 64, 202, 21, 246, 146, 238, 128, 104, 14, 74, 42, 7, 95, 109, 87, 130, 18, 216, 253, 136, 167, 215, 161, 56, 225, 13, 113, 111, 196, 213, 139, 234, 167, 88, 73, 77, 40, 111, 215, 77, 79, 182, 128, 96, 68, 255, 172, 154, 65, 155, 157, 207, 97, 34, 201, 244, 143, 161, 114, 196, 168, 128, 86, 104, 241, 78, 33, 106, 124, 121, 245, 46, 97, 20, 33, 239, 15, 167, 77, 81, 231, 76, 170, 247, 135, 117, 6, 203, 57, 190, 46, 226, 44, 218, 45, 10, 85, 147, 41, 152, 108, 244, 27, 223, 134, 196, 87, 208, 160, 187, 173, 53, 120, 79, 17, 4, 150, 162, 18, 219, 36, 43, 216, 202, 91, 63, 21, 31, 90, 178, 247, 141, 105, 91, 16, 203, 20, 146, 228, 176, 69, 20, 48, 56, 74, 58, 229, 134, 55, 242, 55, 0, 171, 236, 219, 92, 36, 230, 125, 80, 252, 222, 223, 141, 197, 47, 83, 24, 228, 119, 122, 3, 113, 145, 85, 162, 117, 176, 92, 184, 24, 61, 24, 147, 139, 207, 160, 181, 50, 188, 6, 102, 174, 105, 213, 107, 140, 6, 203, 132, 243, 126, 10, 93, 6, 81, 60, 98, 154, 39, 114, 12, 156, 203, 179, 191, 225, 101, 63, 46, 248, 73, 7, 239, 17, 109, 130, 43, 166, 222, 245, 185, 40, 79, 205, 57, 219, 116, 193, 201, 114, 232, 74, 49, 87, 197, 211, 204, 133, 62, 23, 126, 233, 63, 0, 74, 232, 61, 198, 37, 159, 157, 241, 192, 144, 123, 95, 179, 241, 241, 28, 59, 230, 8, 117, 34, 3, 30, 108, 120, 106, 126, 1, 218, 100, 174, 94, 96, 88, 23, 21, 137, 115, 254, 25, 41, 232, 132, 155, 67, 200, 92, 8, 164, 77, 206, 207, 231, 147, 218, 36, 107, 40, 185, 161, 3, 157, 184, 246, 76, 144, 254, 103, 185, 104, 204, 42, 197, 165, 188, 236, 141, 129, 64, 55, 216, 122, 102, 95, 245, 171, 120, 166, 140, 22, 51, 219, 164, 21, 248, 228, 199, 137, 128, 242, 82, 201, 148, 97, 84, 123, 192, 223, 200, 118, 212, 89, 140, 29, 49, 83, 99, 46, 101, 152, 58, 61, 47, 212, 239, 74, 99, 81, 115, 38, 91, 236, 5, 119, 131, 109, 6, 190, 217, 104, 161, 107, 182, 255, 83, 85, 204, 254, 131, 163, 149, 50, 68, 113, 181, 70, 12, 10, 42, 91, 240, 13, 77, 63, 111, 163, 78, 102, 235, 25, 53, 115, 0, 166, 135, 221, 30, 116, 2, 152, 83, 115, 51, 111, 165, 68, 172, 162, 106, 249, 128, 31, 178, 178, 32, 162, 104, 41, 7, 235, 25, 114, 224, 126, 205, 78, 112, 45, 87, 217, 145, 233, 222, 162, 49, 203, 28, 124, 96, 13, 2, 205, 177, 67, 227, 127, 86, 97, 55, 141, 162, 231, 245, 223, 145, 79, 143, 217, 51, 235, 88, 80, 135, 156, 100, 225, 81, 179, 23, 167, 209, 105, 178, 216, 86, 130, 187, 89, 91, 176, 23, 61, 205, 48, 197, 31, 110, 17, 194, 89, 232, 245, 1, 231, 165, 175, 17, 139, 172, 153, 223, 120, 169, 240, 222, 101, 90, 198, 97, 236, 202, 201, 52, 156, 182, 202, 116, 250, 167, 153, 187, 128, 12, 46, 37, 116, 161, 88, 104, 56, 234, 230, 35, 142, 38, 8, 210, 24, 184, 193, 224, 38, 251, 201, 230, 39, 217, 127, 61, 223, 80, 254, 200, 175, 60, 87, 139, 238, 111, 119, 16, 2, 86, 90, 194, 160, 177, 137, 222, 27, 234, 187, 64, 213, 133, 110, 152, 45, 45, 138, 111, 146, 37, 98, 26, 224, 126, 173, 211, 11, 119, 141, 216, 7, 140, 181, 43, 97, 21, 254, 255, 202, 104, 106, 58, 0, 143, 33, 239, 169, 116, 58, 114, 20, 164, 76, 122, 37, 63, 18, 138, 204, 170, 204, 133, 121, 125, 69, 49, 138, 3, 178, 9, 140, 11, 47, 87, 179, 54, 79, 195, 111, 192, 62, 226, 32, 175, 140, 147, 54, 178, 108, 188, 170, 122, 156, 50, 221, 139, 33, 212, 189, 51, 83, 156, 221, 235, 154, 108, 83, 187, 184, 201, 207, 1, 176, 198, 24, 96, 18, 118, 166, 109, 165, 57, 202, 20, 228, 225, 218, 27, 108, 216, 85, 155, 234, 111, 227, 211, 43, 207, 233, 71, 165, 64, 197, 165, 205, 109, 202, 13, 110, 148, 132, 2, 45, 174, 83, 121, 75, 112, 163, 40, 50, 224, 133, 170, 59, 59, 186, 185, 126, 198, 17, 192, 188, 79, 187, 178, 6, 184, 242, 112, 135, 132, 144, 42, 113, 165, 99, 183, 241, 123, 107, 236, 241, 170, 245, 110, 179, 200, 162, 173, 31, 22, 163, 1, 39, 192, 61, 91, 118, 141, 114, 9, 24, 209, 148, 214, 85, 205, 13, 81, 82, 100, 111, 59, 163, 191, 21, 238, 57, 111, 253, 156, 217, 80, 28, 40, 133, 167, 187, 117, 168, 224, 53, 248, 254, 29, 207, 83, 97, 149, 251, 216, 255, 79, 93, 32, 122, 242, 205, 184, 89, 155, 80, 114, 61, 37, 232, 31, 81, 9, 212, 205, 215, 237, 194, 166, 26, 151, 214, 121, 28, 235, 125, 19, 182, 36, 131, 10, 185, 233, 155, 244, 119, 40, 54, 218, 105, 4, 238, 96, 186, 110, 210, 112, 96, 173, 182, 21, 249, 153, 39, 128, 75, 76, 32, 252, 140, 100, 115, 65, 238, 165, 160, 203, 131, 109, 245, 26, 138, 225, 255, 76, 124, 233, 201, 102, 202, 101, 172, 205, 83, 160, 40, 88, 143, 216, 62, 0, 140, 91, 140, 43, 187, 31, 150, 83, 18, 247, 59, 189, 225, 130, 159, 184, 94, 43, 133, 250, 178, 111, 140, 178, 125, 235, 123, 196, 192, 65, 113, 150, 92, 78, 57, 87, 141, 7, 149, 68, 179, 144, 159, 65, 163, 197, 182, 255, 155, 152, 76, 243, 140, 240, 188, 184, 228, 244, 238, 71, 65, 119, 255, 95, 198, 73, 175, 18, 88, 117, 55, 234, 175, 149, 255, 160, 236, 126, 160, 208, 5, 255, 200, 245, 174, 69, 7, 245, 243, 92, 230, 201, 237, 95, 75, 151, 177, 149, 72, 144, 135, 58, 221, 207, 114, 150, 83, 37, 98, 130, 93, 249, 51, 1, 201, 221, 35, 159, 213, 47, 76, 180, 65, 226, 242, 48, 241, 23, 197, 157, 50, 166, 114, 252, 215, 71, 253, 102, 69, 90, 167, 102, 197, 66, 95, 55, 232, 149, 84, 55, 0, 50, 11, 127, 75, 216, 128, 248, 154, 218, 170, 120, 244, 147, 227, 188, 140, 4, 203, 74, 196, 181, 23, 31, 223, 250, 243, 129, 123, 125, 167, 196, 229, 94, 115, 168, 30, 199, 157, 177, 133, 177, 4, 141, 4, 195, 42, 8, 9, 152, 79, 166, 47, 76, 13, 170, 16, 222, 254, 200, 180, 112, 138, 89, 35, 221, 234, 30, 238, 192, 113, 27, 245, 239, 87, 120, 219, 94, 70, 168, 84, 218, 57, 81, 3, 162, 179, 49, 99, 233, 24, 99, 163, 13, 185, 83, 13, 16, 84, 248, 211, 106, 17, 102, 46, 101, 12, 20, 101, 136, 117, 224, 132, 233, 128, 230, 98, 114, 46, 254, 90, 240, 16, 167, 224, 228, 166, 161, 218, 57, 141, 150, 111, 73, 59, 34, 168, 48, 191, 230, 101, 63, 99, 21, 190, 192, 128, 114, 182, 51, 205, 152, 60, 249, 1, 115, 152, 115, 106, 8, 28, 235, 172, 197, 49, 233, 14, 155, 32, 26, 73, 248, 46, 75, 225, 180, 227, 177, 199, 155, 165, 72, 132, 200, 75, 84, 242, 4, 144, 253, 92, 77, 165, 63, 118, 12, 164, 122, 188, 30, 223, 192, 102, 170, 55, 233, 228, 33, 98, 95, 141, 125, 174, 207, 125, 121, 182, 208, 161, 119, 16, 164, 70, 110, 153, 120, 79, 40, 179, 12, 72, 202, 240, 236, 126, 69, 135, 4, 67, 115, 24, 20, 196, 29, 146, 216, 118, 44, 244, 16, 227, 252, 146, 124, 253, 103, 180, 3, 158, 230, 102, 65, 36, 243, 227, 21, 196, 216, 22, 242, 39, 184, 86, 47, 73, 15, 184, 207, 69, 217, 80, 124, 18, 177, 131, 253, 96, 20, 46, 133, 87, 255, 195, 59, 201, 114, 179, 95, 29, 146, 117, 140, 147, 222, 72, 189, 19, 235, 245, 22, 92, 168, 229, 248, 242, 197, 219, 216, 34, 100, 217, 179, 39, 233, 13, 234, 153, 35, 111, 171, 66, 56, 68, 108, 66, 165, 220, 164, 255, 28, 242, 29, 169, 136, 145, 75, 236, 60, 103, 38, 245, 174, 119, 124, 179, 159, 70, 164, 12, 101, 120, 188, 4, 204, 234, 144, 228, 248, 1, 117, 105, 54, 186, 24, 89, 149, 189, 69, 171, 189, 55, 32, 75, 122, 170, 116, 54, 64, 134, 141, 243, 62, 35, 4, 130, 22, 169, 193, 125, 23, 14, 212, 90, 158, 127, 28, 100, 2, 253, 85, 177, 66, 214, 161, 78, 214, 154, 51, 69, 130, 145, 85, 21, 210, 225, 215, 19, 40, 194, 127, 189, 161, 88, 56, 59, 220, 76, 122, 210, 151, 24, 83, 129, 162, 6, 117, 234, 25, 171, 109, 182, 146, 112, 174, 214, 124, 122, 213, 60, 33, 157, 97, 62, 47, 146, 150, 0, 11, 225, 163, 200, 138, 66, 8, 136, 198, 58, 117, 45, 246, 96, 118, 94, 224, 44, 156, 114, 197, 115, 246, 152, 55, 56, 126, 230, 61, 35, 124, 205, 157, 96, 136, 125, 202, 211, 233, 229, 37, 23, 14, 235, 121, 84, 98, 230, 172, 164, 238, 68, 183, 60, 81, 32, 31, 132, 38, 233, 187, 193, 3, 67, 149, 66, 238, 114, 61, 165, 217, 145, 113, 122, 199, 201, 129, 73, 26, 20, 222, 245, 255, 133, 192, 27, 65, 94, 92, 227, 144, 217, 96, 118, 148, 147, 199, 32, 115, 124, 202, 26, 155, 51, 123, 164, 216, 211, 35
,0x4, 0x2, 0x5, 0x5d, 0x50, 0x5, 0xc, 0x5e, 0x57, 0x2, 0x3, 0x56, 0x55, 0xe, 0x52, 0x1, 0x53, 0xb, 0x2, 0xd, 0x56, 0xa, 0x56, 0x5d, 0x5b, 0x2, 0x54, 0x57, 0xd, 0x50, 0x55, 0x54
};

void xor(unsigned char* dst, const unsigned char* src){
    for(int i = 0; i < 32; i++)
        dst[i] = dst[i] ^ src[i];
}

int verify(uint64_t key, int i){
    void * handle;
    int (*check)(uint64_t);
    char *error;
    char lib[] = "./locks/lock.so.000";
    snprintf(lib + 16, 4, "%03x", i);

    handle = dlopen (lib, RTLD_LAZY);
    check = dlsym(handle, "check");
    if((error = dlerror()) != NULL) {
        fputs(error, stderr);
        exit(1);
    }

    int ret = check(key);

    dlclose(handle);
    return ret;
}

#pragma GCC push_options
#pragma GCC optimize ("Og")
int main(int argc, char const *argv[]) {
    __int128_t e = 0;

    union {
        unsigned char digest[64];
        uint64_t a[8];
        uint16_t b[32];
        __uint128_t temp[4];
    } u;

    mpz_t s, t;
    mpz_init(t);
    mpz_init(s);
    FILE* fp = fopen("passkey.txt", "r");
    if(fp == NULL){
        fputs("Cannot print flag without key file\n", stderr);
        return -1;
    }

    while(e != -1){
        mpz_set_ui(s, 0);
        memset(&u, 0, sizeof(u));
        rewind(fp);
        int i = 0;

        for(; i < 128; i++){
            for(int j = 0; j < 8; j++){
                int ret = fscanf(fp, "%lu", u.a + j);
                if(verify(u.a[j], i * 8 + j) != 0 || ret <= 0){
                    fprintf(stderr, "Key file error!\n");
                    return -1;
                }
                u.temp[j / 2] ^= (u.temp[j / 2] << 32) | (u.temp[j / 2] >> 96);
                Hash((unsigned char *)&u, sizeof(u), u.digest);
            }
            u.a[4] &= 0x7c00;
            xor(u.digest, w + i * 32);
            mpz_set_str(t, (const char*) u.digest, 18);
            if( (e >> (127 - i)) & 1)
                mpz_add(s, s, t);
        }
        u.b[16] = 0x38;
        xor(u.digest, w + i * 32);
        mpz_set_str(t, (const char*) u.digest, 18);
        if(mpz_cmp(s, t) == 0){
            printf("Oh, sure! Flag is flxg{%016lx%016lx}.\n", (unsigned long) (e >> 64), (unsigned long) e);
            goto done;
        }
        e++;
    }

    printf("Flag not found. There must be something wrong...\n");

done:
    mpz_clear(s);
    mpz_clear(t);
    return 0;
}
#pragma GCC pop_options