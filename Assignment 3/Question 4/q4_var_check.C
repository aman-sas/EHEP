#define q4_var_check_cxx
#include "q4_var_check.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector> 
#include "MyElectron.h"
#include "MyMuon.h" 
#include "MyGenParticle.h"

void q4_var_check::Loop()
{
//   In a ROOT session, you can do:
//      root> .L q4_var_check.C
//      root> q4_var_check t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   TFile *f = new TFile("q4_tree.root", "RECREATE");
   TTree *T = new TTree("T","tree with vectors for diffrent particles");

   std::vector<MyElectron> *electrons = new std::vector<MyElectron>();
   std::vector<MyMuon> *muons = new std::vector<MyMuon>();
   std::vector<MyGenParticle> *Gen_Ps = new std::vector<MyGenParticle>();

   T->Branch("Electrons", "std::vector<MyElectron>", &electrons);
   T->Branch("Muons", "std::vector<MyMuon>", &muons);
   T->Branch("GenPs", "std::vector<MyGenParticle>", &Gen_Ps);

   if (fChain == 0) return;
   
   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      electrons->clear();
      muons->clear();
      Gen_Ps->clear();

      if (nGenParticle > 0) {
         for (int i = 0; i < nGenParticle; i++) {
            MyGenParticle gen_p;
            gen_p.set_GP_Px(genParticlePx[i]);
            gen_p.set_GP_Py(genParticlePy[i]);
            gen_p.set_GP_Pz(genParticlePz[i]);
            Gen_Ps->push_back(gen_p);
         }
      }

      if (nMuon > 0) {
         for (int i = 0; i < nMuon; i++) {
            MyMuon muon;
            muon.set_m_Px(muonPx[i]);
            muon.set_m_Py(muonPy[i]);
            muon.set_m_Pz(muonPz[i]);
            muons->push_back(muon);
         }
      }

      if (nElectron > 0) {
         for (int i = 0; i < nElectron; i++) {
            MyElectron electron;
            electron.set_e_Px(electronPx[i]);
            electron.set_e_Py(electronPy[i]);
            electron.set_e_Pz(electronPz[i]);
            electrons->push_back(electron);
         }
      }

      T->Fill();
            
   }
   
   f->Write();
   f->Close();

   delete electrons;
   delete muons;
   delete Gen_Ps; 
}
