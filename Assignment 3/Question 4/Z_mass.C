#define Z_mass_cxx
#include "Z_mass.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <Math/Vector4D.h>

void Z_mass::Loop()
{
//   In a ROOT session, you can do:
//      root> .L Z_mass.C
//      root> Z_mass t
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

   TFile *f = new TFile("q4_z_mass.root", "RECREATE");
   TH1F *mu_z_mass = new TH1F("mu_z_mass", "Z mass from muons", 100, 0, 200);
   TH1F *el_z_mass = new TH1F("el_z_mass", "Z mass from electrons", 100, 0, 200);
   TH1F *gen_z_mass = new TH1F("gen_z_mass", "Z mass from generated particles", 100, 0, 200);

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if (Muons_ == 2) {
         ROOT::Math::PxPyPzMVector mu1(Muons_px[0], Muons_py[0], Muons_pz[0], 0.);
         ROOT::Math::PxPyPzMVector mu2(Muons_px[1], Muons_py[1], Muons_pz[1], 0.);
         ROOT::Math::PxPyPzMVector z = mu1 + mu2;
         mu_z_mass->Fill(z.M());
      }
      if (Electrons_ == 2) {
         ROOT::Math::PxPyPzMVector el1(Electrons_px[0], Electrons_py[0], Electrons_pz[0], 0.);
         ROOT::Math::PxPyPzMVector el2(Electrons_px[1], Electrons_py[1], Electrons_pz[1], 0.);
         ROOT::Math::PxPyPzMVector z = el1 + el2;
         el_z_mass->Fill(z.M());
      }
      if (GenPs_ == 2) {
         ROOT::Math::PxPyPzMVector genp1(GenPs_px[0], GenPs_py[0], GenPs_pz[0], 0.);
         ROOT::Math::PxPyPzMVector genp2(GenPs_px[1], GenPs_py[1], GenPs_pz[1], 0.);
         ROOT::Math::PxPyPzMVector z = genp1 + genp2;
         gen_z_mass->Fill(z.M());
      }
   }

   TCanvas *c1 = new TCanvas("c1", "c1", 800, 600);
   mu_z_mass->Draw();
   c1->SaveAs("mu_z_mass.png");
   el_z_mass->Draw();
   c1->SaveAs("el_z_mass.png");
   gen_z_mass->Draw();
   c1->Update();
   c1->SaveAs("gen_z_mass.png");

   f->Write();
   f->Close();   
}

