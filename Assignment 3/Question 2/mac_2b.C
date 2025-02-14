#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <math.h>
#include <TLorentzVector.h>
#include <TCanvas.h>
#include <iostream>

void mac_2a() {
    // Open the ROOT file
    TFile *file = new TFile("ntuple_array.root");
    TDirectoryFile *dir = (TDirectoryFile*)file->Get("ntupleProducer");
    TTree *tree = (TTree*)dir->Get("tree;2");

    // Define variables to hold the data
    Float_t muonPx[10], muonPy[10], muonPz[10];
    Int_t nMuon;

    // Set branch addresses
    tree->SetBranchAddress("muonPx", muonPx);
    tree->SetBranchAddress("muonPy", muonPy);
    tree->SetBranchAddress("muonPz", muonPz);
    tree->SetBranchAddress("nMuon", &nMuon);

    // Create a histogram to store the invariant mass of the Z boson
    TH1F *h_mass = new TH1F("h_mass", "Mass of Reconstructed Z Boson;Mass (GeV/c^2);Entries", 100, 60, 120);

    // Loop over the entries in the TTree
    Int_t nentries = (Int_t)tree->GetEntries();
    cout << nentries << endl;

    for (Int_t i = 0; i < nentries; i++) {
        tree->GetEntry(i);
        if (nMuon < 2) continue;
        Float_t p0 = pow((pow(muonPx[0], 2) + pow(muonPy[0], 2) + pow(muonPz[0], 2)),0.5);
        Float_t p1 = pow((pow(muonPx[1], 2) + pow(muonPy[1], 2) + pow(muonPz[1], 2)),0.5);
        Float_t mass = pow((2*(p0*p1 - muonPx[0]*muonPx[1] - muonPy[0]*muonPy[1] - muonPz[0]*muonPz[1])),0.5);
        
        h_mass->Fill(mass);        
    }

    // Draw the histogram
    h_mass->Draw();
}
