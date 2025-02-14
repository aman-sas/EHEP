//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Oct 19 01:14:50 2024 by ROOT version 6.32.06
// from TTree T/tree with vectors for diffrent particles
// found on file: q4_tree.root
//////////////////////////////////////////////////////////

#ifndef Z_mass_h
#define Z_mass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "MyElectron.h"
#include "vector"
#include "MyMuon.h"
#include "vector"
#include "MyGenParticle.h"

class Z_mass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxElectrons = 3;
   static constexpr Int_t kMaxMuons = 3;
   static constexpr Int_t kMaxGenPs = 4;

   // Declaration of leaf types
   Int_t           Electrons_;
   Float_t         Electrons_px[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_py[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_pz[kMaxElectrons];   //[Electrons_]
   Int_t           Muons_;
   Float_t         Muons_px[kMaxMuons];   //[Muons_]
   Float_t         Muons_py[kMaxMuons];   //[Muons_]
   Float_t         Muons_pz[kMaxMuons];   //[Muons_]
   Int_t           GenPs_;
   Float_t         GenPs_px[kMaxGenPs];   //[GenPs_]
   Float_t         GenPs_py[kMaxGenPs];   //[GenPs_]
   Float_t         GenPs_pz[kMaxGenPs];   //[GenPs_]

   // List of branches
   TBranch        *b_Electrons_;   //!
   TBranch        *b_Electrons_px;   //!
   TBranch        *b_Electrons_py;   //!
   TBranch        *b_Electrons_pz;   //!
   TBranch        *b_Muons_;   //!
   TBranch        *b_Muons_px;   //!
   TBranch        *b_Muons_py;   //!
   TBranch        *b_Muons_pz;   //!
   TBranch        *b_GenPs_;   //!
   TBranch        *b_GenPs_px;   //!
   TBranch        *b_GenPs_py;   //!
   TBranch        *b_GenPs_pz;   //!

   Z_mass(TTree *tree=0);
   virtual ~Z_mass();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual bool     Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Z_mass_cxx
Z_mass::Z_mass(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("q4_tree.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("q4_tree.root");
      }
      f->GetObject("T",tree);

   }
   Init(tree);
}

Z_mass::~Z_mass()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Z_mass::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Z_mass::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Z_mass::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Electrons", &Electrons_, &b_Electrons_);
   fChain->SetBranchAddress("Electrons.px", Electrons_px, &b_Electrons_px);
   fChain->SetBranchAddress("Electrons.py", Electrons_py, &b_Electrons_py);
   fChain->SetBranchAddress("Electrons.pz", Electrons_pz, &b_Electrons_pz);
   fChain->SetBranchAddress("Muons", &Muons_, &b_Muons_);
   fChain->SetBranchAddress("Muons.px", Muons_px, &b_Muons_px);
   fChain->SetBranchAddress("Muons.py", Muons_py, &b_Muons_py);
   fChain->SetBranchAddress("Muons.pz", Muons_pz, &b_Muons_pz);
   fChain->SetBranchAddress("GenPs", &GenPs_, &b_GenPs_);
   fChain->SetBranchAddress("GenPs.px", GenPs_px, &b_GenPs_px);
   fChain->SetBranchAddress("GenPs.py", GenPs_py, &b_GenPs_py);
   fChain->SetBranchAddress("GenPs.pz", GenPs_pz, &b_GenPs_pz);
   Notify();
}

bool Z_mass::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return true;
}

void Z_mass::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Z_mass::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Z_mass_cxx
