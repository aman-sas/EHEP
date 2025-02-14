//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Oct 18 23:01:13 2024 by ROOT version 6.32.06
// from TTree tree/tree
// found on file: ntuple_array.root
//////////////////////////////////////////////////////////

#ifndef q4_var_check_h
#define q4_var_check_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class q4_var_check {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   ULong64_t       run;
   ULong64_t       event;
   ULong64_t       lumi;
   UInt_t          nPV;
   Float_t         PVx;
   Float_t         PVy;
   Float_t         PVz;
   Int_t           nGenParticle;
   Float_t         genParticlePx[4];   //[nGenParticle]
   Float_t         genParticlePy[4];   //[nGenParticle]
   Float_t         genParticlePz[4];   //[nGenParticle]
   Float_t         genParticlePt[4];   //[nGenParticle]
   Float_t         genParticleEta[4];   //[nGenParticle]
   Float_t         genParticlePhi[4];   //[nGenParticle]
   Int_t           genParticleCharge[4];   //[nGenParticle]
   Int_t           genParticlePdgId[4];   //[nGenParticle]
   Int_t           nMuon;
   Float_t         muonPx[3];   //[nMuon]
   Float_t         muonPy[3];   //[nMuon]
   Float_t         muonPz[3];   //[nMuon]
   Float_t         muonPt[3];   //[nMuon]
   Float_t         muonEta[3];   //[nMuon]
   Float_t         muonPhi[3];   //[nMuon]
   Int_t           muonCharge[3];   //[nMuon]
   Float_t         muonR04SumChargedHadronPt[3];   //[nMuon]
   Float_t         muonR04SumChargedParticlePt[3];   //[nMuon]
   Float_t         muonR04SumNeutralHadronEt[3];   //[nMuon]
   Float_t         muonR04SumPhotonEt[3];   //[nMuon]
   Float_t         muonR04SumPUPt[3];   //[nMuon]
   Bool_t          muonIsPF[3];   //[nMuon]
   Bool_t          muonIsGlobal[3];   //[nMuon]
   Bool_t          muonIsTracker[3];   //[nMuon]
   Bool_t          muonIsICHEPMedium[3];   //[nMuon]
   Float_t         muonDz[3];   //[nMuon]
   Float_t         muonDxy[3];   //[nMuon]
   Int_t           nElectron;
   Float_t         electronPx[3];   //[nElectron]
   Float_t         electronPy[3];   //[nElectron]
   Float_t         electronPz[3];   //[nElectron]
   Float_t         electronPt[3];   //[nElectron]
   Float_t         electronEta[3];   //[nElectron]
   Float_t         electronPhi[3];   //[nElectron]
   Float_t         electronDxy[3];   //[nElectron]
   Float_t         electronDz[3];   //[nElectron]
   Int_t           electronCharge[3];   //[nElectron]
   Float_t         electronR03SumChargedHadronPt[3];   //[nElectron]
   Float_t         electronR03SumChargedParticlePt[3];   //[nElectron]
   Float_t         electronR03SumNeutralHadronEt[3];   //[nElectron]
   Float_t         electronR03SumPhotonEt[3];   //[nElectron]
   Float_t         electronR03SumPUPt[3];   //[nElectron]
   Int_t           electron_nmissinginnerhits[3];   //[nElectron]
   Bool_t          electron_pass_conversion[3];   //[nElectron]
   Bool_t          electron_mva_medium_Spring16[3];   //[nElectron]
   Bool_t          electron_mva_tight_Spring16[3];   //[nElectron]
   Float_t         electron_mva_value_Spring16[3];   //[nElectron]
   Int_t           electron_mva_category_Spring16[3];   //[nElectron]
   Bool_t          electron_cutId_veto_Summer16[3];   //[nElectron]
   Bool_t          electron_cutId_loose_Summer16[3];   //[nElectron]
   Bool_t          electron_cutId_medium_Summer16[3];   //[nElectron]
   Bool_t          electron_cutId_tight_Summer16[3];   //[nElectron]

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_event;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_nPV;   //!
   TBranch        *b_PVx;   //!
   TBranch        *b_PVy;   //!
   TBranch        *b_PVz;   //!
   TBranch        *b_nGenParticle;   //!
   TBranch        *b_genParticlePx;   //!
   TBranch        *b_genParticlePy;   //!
   TBranch        *b_genParticlePz;   //!
   TBranch        *b_genParticlePt;   //!
   TBranch        *b_genParticleEta;   //!
   TBranch        *b_genParticlePhi;   //!
   TBranch        *b_genParticleCharge;   //!
   TBranch        *b_genParticlePdgId;   //!
   TBranch        *b_nMuon;   //!
   TBranch        *b_muonPx;   //!
   TBranch        *b_muonPy;   //!
   TBranch        *b_muonPz;   //!
   TBranch        *b_muonPt;   //!
   TBranch        *b_muonEta;   //!
   TBranch        *b_muonPhi;   //!
   TBranch        *b_muonCharge;   //!
   TBranch        *b_muonR04SumChargedHadronPt;   //!
   TBranch        *b_muonR04SumChargedParticlePt;   //!
   TBranch        *b_muonR04SumNeutralHadronEt;   //!
   TBranch        *b_muonR04SumPhotonEt;   //!
   TBranch        *b_muonR04SumPUPt;   //!
   TBranch        *b_muonIsPF;   //!
   TBranch        *b_muonIsGlobal;   //!
   TBranch        *b_muonIsTracker;   //!
   TBranch        *b_muonIsICHEPMedium;   //!
   TBranch        *b_muonDz;   //!
   TBranch        *b_muonDxy;   //!
   TBranch        *b_nElectron;   //!
   TBranch        *b_electronPx;   //!
   TBranch        *b_electronPy;   //!
   TBranch        *b_electronPz;   //!
   TBranch        *b_electronPt;   //!
   TBranch        *b_electronEta;   //!
   TBranch        *b_electronPhi;   //!
   TBranch        *b_electronDxy;   //!
   TBranch        *b_electronDz;   //!
   TBranch        *b_electronCharge;   //!
   TBranch        *b_electronR03SumChargedHadronPt;   //!
   TBranch        *b_electronR03SumChargedParticlePt;   //!
   TBranch        *b_electronR03SumNeutralHadronEt;   //!
   TBranch        *b_electronR03SumPhotonEt;   //!
   TBranch        *b_electronR03SumPUPt;   //!
   TBranch        *b_electron_nmissinginnerhits;   //!
   TBranch        *b_electron_pass_conversion;   //!
   TBranch        *b_electron_mva_medium_Spring16;   //!
   TBranch        *b_electron_mva_tight_Spring16;   //!
   TBranch        *b_electron_mva_value_Spring16;   //!
   TBranch        *b_electron_mva_category_Spring16;   //!
   TBranch        *b_electron_cutId_veto_Summer16;   //!
   TBranch        *b_electron_cutId_loose_Summer16;   //!
   TBranch        *b_electron_cutId_medium_Summer16;   //!
   TBranch        *b_electron_cutId_tight_Summer16;   //!

   q4_var_check(TTree *tree=0);
   virtual ~q4_var_check();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual bool     Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef q4_var_check_cxx
q4_var_check::q4_var_check(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("ntuple_array.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("ntuple_array.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("ntuple_array.root:/ntupleProducer");
      dir->GetObject("tree",tree);

   }
   Init(tree);
}

q4_var_check::~q4_var_check()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t q4_var_check::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t q4_var_check::LoadTree(Long64_t entry)
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

void q4_var_check::Init(TTree *tree)
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

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("nPV", &nPV, &b_nPV);
   fChain->SetBranchAddress("PVx", &PVx, &b_PVx);
   fChain->SetBranchAddress("PVy", &PVy, &b_PVy);
   fChain->SetBranchAddress("PVz", &PVz, &b_PVz);
   fChain->SetBranchAddress("nGenParticle", &nGenParticle, &b_nGenParticle);
   fChain->SetBranchAddress("genParticlePx", genParticlePx, &b_genParticlePx);
   fChain->SetBranchAddress("genParticlePy", genParticlePy, &b_genParticlePy);
   fChain->SetBranchAddress("genParticlePz", genParticlePz, &b_genParticlePz);
   fChain->SetBranchAddress("genParticlePt", genParticlePt, &b_genParticlePt);
   fChain->SetBranchAddress("genParticleEta", genParticleEta, &b_genParticleEta);
   fChain->SetBranchAddress("genParticlePhi", genParticlePhi, &b_genParticlePhi);
   fChain->SetBranchAddress("genParticleCharge", genParticleCharge, &b_genParticleCharge);
   fChain->SetBranchAddress("genParticlePdgId", genParticlePdgId, &b_genParticlePdgId);
   fChain->SetBranchAddress("nMuon", &nMuon, &b_nMuon);
   fChain->SetBranchAddress("muonPx", muonPx, &b_muonPx);
   fChain->SetBranchAddress("muonPy", muonPy, &b_muonPy);
   fChain->SetBranchAddress("muonPz", muonPz, &b_muonPz);
   fChain->SetBranchAddress("muonPt", muonPt, &b_muonPt);
   fChain->SetBranchAddress("muonEta", muonEta, &b_muonEta);
   fChain->SetBranchAddress("muonPhi", muonPhi, &b_muonPhi);
   fChain->SetBranchAddress("muonCharge", muonCharge, &b_muonCharge);
   fChain->SetBranchAddress("muonR04SumChargedHadronPt", muonR04SumChargedHadronPt, &b_muonR04SumChargedHadronPt);
   fChain->SetBranchAddress("muonR04SumChargedParticlePt", muonR04SumChargedParticlePt, &b_muonR04SumChargedParticlePt);
   fChain->SetBranchAddress("muonR04SumNeutralHadronEt", muonR04SumNeutralHadronEt, &b_muonR04SumNeutralHadronEt);
   fChain->SetBranchAddress("muonR04SumPhotonEt", muonR04SumPhotonEt, &b_muonR04SumPhotonEt);
   fChain->SetBranchAddress("muonR04SumPUPt", muonR04SumPUPt, &b_muonR04SumPUPt);
   fChain->SetBranchAddress("muonIsPF", muonIsPF, &b_muonIsPF);
   fChain->SetBranchAddress("muonIsGlobal", muonIsGlobal, &b_muonIsGlobal);
   fChain->SetBranchAddress("muonIsTracker", muonIsTracker, &b_muonIsTracker);
   fChain->SetBranchAddress("muonIsICHEPMedium", muonIsICHEPMedium, &b_muonIsICHEPMedium);
   fChain->SetBranchAddress("muonDz", muonDz, &b_muonDz);
   fChain->SetBranchAddress("muonDxy", muonDxy, &b_muonDxy);
   fChain->SetBranchAddress("nElectron", &nElectron, &b_nElectron);
   fChain->SetBranchAddress("electronPx", electronPx, &b_electronPx);
   fChain->SetBranchAddress("electronPy", electronPy, &b_electronPy);
   fChain->SetBranchAddress("electronPz", electronPz, &b_electronPz);
   fChain->SetBranchAddress("electronPt", electronPt, &b_electronPt);
   fChain->SetBranchAddress("electronEta", electronEta, &b_electronEta);
   fChain->SetBranchAddress("electronPhi", electronPhi, &b_electronPhi);
   fChain->SetBranchAddress("electronDxy", electronDxy, &b_electronDxy);
   fChain->SetBranchAddress("electronDz", electronDz, &b_electronDz);
   fChain->SetBranchAddress("electronCharge", electronCharge, &b_electronCharge);
   fChain->SetBranchAddress("electronR03SumChargedHadronPt", electronR03SumChargedHadronPt, &b_electronR03SumChargedHadronPt);
   fChain->SetBranchAddress("electronR03SumChargedParticlePt", electronR03SumChargedParticlePt, &b_electronR03SumChargedParticlePt);
   fChain->SetBranchAddress("electronR03SumNeutralHadronEt", electronR03SumNeutralHadronEt, &b_electronR03SumNeutralHadronEt);
   fChain->SetBranchAddress("electronR03SumPhotonEt", electronR03SumPhotonEt, &b_electronR03SumPhotonEt);
   fChain->SetBranchAddress("electronR03SumPUPt", electronR03SumPUPt, &b_electronR03SumPUPt);
   fChain->SetBranchAddress("electron_nmissinginnerhits", electron_nmissinginnerhits, &b_electron_nmissinginnerhits);
   fChain->SetBranchAddress("electron_pass_conversion", electron_pass_conversion, &b_electron_pass_conversion);
   fChain->SetBranchAddress("electron_mva_medium_Spring16", electron_mva_medium_Spring16, &b_electron_mva_medium_Spring16);
   fChain->SetBranchAddress("electron_mva_tight_Spring16", electron_mva_tight_Spring16, &b_electron_mva_tight_Spring16);
   fChain->SetBranchAddress("electron_mva_value_Spring16", electron_mva_value_Spring16, &b_electron_mva_value_Spring16);
   fChain->SetBranchAddress("electron_mva_category_Spring16", electron_mva_category_Spring16, &b_electron_mva_category_Spring16);
   fChain->SetBranchAddress("electron_cutId_veto_Summer16", electron_cutId_veto_Summer16, &b_electron_cutId_veto_Summer16);
   fChain->SetBranchAddress("electron_cutId_loose_Summer16", electron_cutId_loose_Summer16, &b_electron_cutId_loose_Summer16);
   fChain->SetBranchAddress("electron_cutId_medium_Summer16", electron_cutId_medium_Summer16, &b_electron_cutId_medium_Summer16);
   fChain->SetBranchAddress("electron_cutId_tight_Summer16", electron_cutId_tight_Summer16, &b_electron_cutId_tight_Summer16);
   Notify();
}

bool q4_var_check::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return true;
}

void q4_var_check::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t q4_var_check::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef q4_var_check_cxx
