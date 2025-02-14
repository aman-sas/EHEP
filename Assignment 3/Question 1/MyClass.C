#define MyClass_cxx
#include "MyClass.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void MyClass::Loop()
{
//   In a ROOT session, you can do:
//      root> .L MyClass.C
//      root> MyClass t
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
   TH1F *pt_histo = new TH1F("pt_histo", "Histogram for pt", 100, 0, 5);
   TH2F *py_px_histo = new TH2F("py_px_histo", "Histogram for py vs px", 100, -5, 5, 100, -5, 5);

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      Float_t hPt = 0;
      Int_t h_index = -1;
      if(Events_ > 0){
         for(Int_t j = 0; j < Events_; j++){
            if(Events_pt[j] > hPt){
               hPt = Events_pt[j];
               h_index = j;
            }
         }
         py_px_histo->Fill(Events_px[h_index], Events_py[h_index]);
         pt_histo->Fill(Events_pt[h_index]);
      }
   }
   TCanvas *c1 = new TCanvas("c1", "c1", 800, 800);
   py_px_histo->Draw("colz");
   c1->SaveAs("py_px_histo.png");
   c1->Update();
   pt_histo->Draw();
   c1->SaveAs("pt_histo.png");
}
