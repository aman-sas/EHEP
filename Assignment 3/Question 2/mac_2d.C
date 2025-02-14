#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <math.h>
#include <Math/Vector4D.h>
#include <TCanvas.h>
#include <iostream>

void mac_2d() {
    // Open the ROOT file
    TFile *file = new TFile("ntuple_array.root");
    TDirectoryFile *dir = (TDirectoryFile*)file->Get("ntupleProducer");
    TTree *tree = (TTree*)dir->Get("tree;2");

    // Define variables to hold the data
    Float_t muonPx[10], muonPy[10], muonPz[10], genParticlePx[10], genParticlePy[10], genParticlePz[10];
    Int_t nMuon, nGenParticle;

    // Set branch addresses
    tree->SetBranchAddress("muonPx", muonPx);
    tree->SetBranchAddress("muonPy", muonPy);
    tree->SetBranchAddress("muonPz", muonPz);
    tree->SetBranchAddress("nMuon", &nMuon);
    tree->SetBranchAddress("genParticlePx", genParticlePx);
    tree->SetBranchAddress("genParticlePy", genParticlePy);
    tree->SetBranchAddress("genParticlePz", genParticlePz);
    tree->SetBranchAddress("nGenParticle", &nGenParticle);

    // Create a histogram to store the invariant mass of the Z boson
    TH1F *mass_re = new TH1F("mass_re", "Mass of Reconstructed Z Boson;Mass (GeV/c^2);Entries", 100, 60, 120);
    TH1F *mass_gen = new TH1F("mass_gen", "Mass of Generated Z Boson;Mass (GeV/c^2);Entries", 100, 60, 120);

    // Loop over the entries in the TTree
    Int_t nentries = (Int_t)tree->GetEntries();
    cout << nentries << endl;

    for (Int_t i = 0; i < nentries; i++) {
        tree->GetEntry(i);
        if (nMuon >= 2) {        
            ROOT::Math::PxPyPzMVector zReP;

            for (Int_t j = 0; j < nMuon; j++) {
                ROOT::Math::PxPyPzMVector muonP(muonPx[j], muonPy[j], muonPz[j], 0.);
                zReP += muonP;
            }
        float_t massRe = zReP.M();
        mass_re->Fill(massRe);
        }   

        if (nGenParticle >= 2) {        
            ROOT::Math::PxPyPzMVector zGenP;

            for (Int_t j = 0; j < nGenParticle; j++) {
                ROOT::Math::PxPyPzMVector genParticleP(genParticlePx[j], genParticlePy[j], genParticlePz[j], 0.);
                zGenP += genParticleP;
            }
        float_t massGen = zGenP.M();
        mass_gen->Fill(massGen);
        }     
    }

    // Draw the histogram
    TCanvas *c1 = new TCanvas();

    mass_re->Draw();
    c1->Update();
    c1->SaveAs("mass_re.png");

    mass_gen->Draw();
    c1->Update();
    c1->SaveAs("mass_gen.png");

}
