#include "llvm/InitializePasses.h"
#include "llvm-c/Initialization.h"

using namespace llvm;

/// initializeOutputPrune - Initialize output prone pass
void llvm::initializeOutputPrune(PassRegistry &Registry) {
  initializeOutputPrune(Registry);
}

/// LLVMInitializeOutputprune - C binding for initializeOutputPrune.
void LLVMInitializeOutputPrune(LLVMPassRegistryRef R) {
  initializeOutputPrune(*unwrap(R));
}
