#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <math.h>
#include <TLorentzVector.h>
#include <TCanvas.h>
#include <iostream>

void mac_2b() {
    // Open the ROOT file
    TFile *file = new TFile("ntuple_array.root");
    TDirectoryFile *dir = (TDirectoryFile*)file->Get("ntupleProducer");
    TTree *tree = (TTree*)dir->Get("tree;1");

    // Define variables to hold the data
    Float_t genParticlePx[10], genParticlePy[10], genParticlePz[10];
    Int_t nGenParticle;

    // Set branch addresses
    tree->SetBranchAddress("genParticlePx", genParticlePx);
    tree->SetBranchAddress("genParticlePy", genParticlePy);
    tree->SetBranchAddress("genParticlePz", genParticlePz);
    tree->SetBranchAddress("nGenParticle", &nGenParticle);

    // Create a histogram to store the invariant mass of the Z boson
    TH1F *h_mass = new TH1F("h_mass", "Mass of Generated Z Boson;Mass (GeV/c^2);Entries", 100, 60, 120);

    // Loop over the entries in the TTree
    Int_t nentries = (Int_t)tree->GetEntries();
    cout << nentries << endl;

    for (Int_t i = 0; i < nentries; i++) {
        tree->GetEntry(i);
        if (nGenParticle < 2) continue;
        Float_t p0 = pow((pow(genParticlePx[0], 2) + pow(genParticlePy[0], 2) + pow(genParticlePz[0], 2)),0.5);
        Float_t p1 = pow((pow(genParticlePx[1], 2) + pow(genParticlePy[1], 2) + pow(genParticlePz[1], 2)),0.5);
        Float_t mass = pow((2*(p0*p1 - genParticlePx[0]*genParticlePx[1] - genParticlePy[0]*genParticlePy[1] - genParticlePz[0]*genParticlePz[1])),0.5);
        
        h_mass->Fill(mass);        
    }

    // Draw the histogram
    h_mass->Draw();
}
