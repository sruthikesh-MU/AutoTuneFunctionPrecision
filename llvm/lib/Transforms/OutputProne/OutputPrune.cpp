//===- OutputProne.cpp - Tunes the function for better performance and lower
// precision with error threshold" ---------------===//
//
//===----------------------------------------------------------------------===//

#include "llvm/ADT/Statistic.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
using namespace llvm;

#define DEBUG_TYPE "OutputProne"

namespace {
struct OutputProne : public FunctionPass {
  static char ID; // Pass identification, replacement for typeid
  OutputProne() : FunctionPass(ID) {}

  bool runOnFunction(Function &F) override {

    bool removeAllRemainingStores = false;

    // Keep only 1 store instruction
    for (auto &bb : F) {
      for (auto &instr : bb) {
        if (isa<StoreInst>(instr)) {
          if (removeAllRemainingStores) {
            instr.removeFromParent();
          }
          removeAllRemainingStores = true;
        }
      }
    }
    return false;
  }
};
}
char OutputProne::ID = 0;
static RegisterPass<OutputProne> X("outputprone", "Output pruning pass");
