#define three_c_cxx
#include "three_c.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void three_c::Loop()
{
//   In a ROOT session, you can do:
//      root> .L three_c.C
//      root> three_c t
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

   TH2F *h_pxpy = new TH2F("h_pxpy", "py Vs px", 100, -2.0, 2.0, 100, -2.0, 2.0);
   TH1F *h_pt = new TH1F("h_pt", "pt", 100, 0., 5.0);

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      //Find the object with highest pt and fill its distributions
      Float_t hPt = 0; 
      Int_t h_index = -1;
      if(pt->size() > 0){
         for(Int_t j = 0; j < pt->size(); j++){
            if((*pt)[j] > hPt){
            hPt = (*pt)[j];
            h_index = j;
            }
         }

         h_pxpy->Fill((*px)[h_index], (*py)[h_index]);
         h_pt->Fill((*pt)[h_index]);
      }

   }

   TCanvas *c1 = new TCanvas();
   c1->Divide(2,1);

   c1->cd(1);
   h_pxpy->Draw("colz");
   
   c1->cd(2);
   h_pt->Draw();

   c1->cd();
   c1->SaveAs("three_c.png");


}
