// Copyright 2017 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "bsdiff/patch_writer_factory.h"

#include "bsdiff/endsley_patch_writer.h"
#include "bsdiff/patch_writer.h"

namespace bsdiff {

std::unique_ptr<PatchWriterInterface> CreateBsdiffPatchWriter(
    const std::string& patch_filename) {
  return std::unique_ptr<PatchWriterInterface>(
      new BsdiffPatchWriter(patch_filename));
}

std::unique_ptr<PatchWriterInterface> CreateBSDF2PatchWriter(
    const std::string& patch_filename,
    CompressorType type,
    int brotli_quality) {
  return CreateBSDF2PatchWriter(
      patch_filename, std::vector<CompressorType>{type}, brotli_quality);
}

std::unique_ptr<PatchWriterInterface> CreateBSDF2PatchWriter(
    const std::string& patch_filename,
    const std::vector<CompressorType>& types,
    int brotli_quality) {
  return std::unique_ptr<PatchWriterInterface>(
      new BsdiffPatchWriter(patch_filename, types, brotli_quality));
}

std::unique_ptr<PatchWriterInterface> CreateEndsleyPatchWriter(
    std::vector<uint8_t>* patch,
    CompressorType type,
    int brotli_quality) {
  return std::unique_ptr<PatchWriterInterface>(
      new EndsleyPatchWriter(patch, type, brotli_quality));
}

std::unique_ptr<PatchWriterInterface> CreateEndsleyPatchWriter(
    std::vector<uint8_t>* patch) {
  return std::unique_ptr<PatchWriterInterface>(
      new EndsleyPatchWriter(patch, CompressorType::kNoCompression, 0));
}

}  // namespace bsdiff
