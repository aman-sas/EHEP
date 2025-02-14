#include "ROOT/RDataFrame.hxx"
#include "ROOT/RVec.hxx"
#include "Math/Vector4Dfwd.h"
#include "Math/Vector4D.h"
#include "TCanvas.h"
#include "TH1D.h"
#include "TLatex.h"
#include "TStyle.h"


using namespace ROOT::VecOps;

// Compute the invariant mass of two muon four-vectors
float computeInvariantMass(RVec<float>& pt, RVec<float>& eta, RVec<float>& phi, RVec<float>& mass) {
    ROOT::Math::PtEtaPhiMVector m1(pt[0], eta[0], phi[0], mass[0]);
    ROOT::Math::PtEtaPhiMVector m2(pt[1], eta[1], phi[1], mass[1]);
    return (m1 + m2).mass();
}

float computePt(RVec<float>& pt, RVec<float>& eta, RVec<float>& phi, RVec<float>& mass) {
    ROOT::Math::PtEtaPhiMVector m1(pt[0], eta[0], phi[0], mass[0]);
    ROOT::Math::PtEtaPhiMVector m2(pt[1], eta[1], phi[1], mass[1]);
    return (m1 + m2).Pt();
}

float computeEta(RVec<float>& pt, RVec<float>& eta, RVec<float>& phi, RVec<float>& mass) {
    ROOT::Math::PtEtaPhiMVector m1(pt[0], eta[0], phi[0], mass[0]);
    ROOT::Math::PtEtaPhiMVector m2(pt[1], eta[1], phi[1], mass[1]);
    return (m1 + m2).Eta();
}

float computePhi(RVec<float>& pt, RVec<float>& eta, RVec<float>& phi, RVec<float>& mass) {
    ROOT::Math::PtEtaPhiMVector m1(pt[0], eta[0], phi[0], mass[0]);
    ROOT::Math::PtEtaPhiMVector m2(pt[1], eta[1], phi[1], mass[1]);
    return (m1 + m2).Phi();
}

void dimuonSpectrum_pg() {
    // Enable multi-threading
    // The default here is set to a single thread. You can choose the number of threads based on your system.
    ROOT::EnableImplicitMT(8);

    // Create dataframe from NanoAOD files
    ROOT::RDataFrame df("Events", "Run2012BC_DoubleMuParked_Muons.root");

    // Select events with exactly two muons
    auto df_2mu = df.Filter("nMuon == 2", "Events with exactly two muons");

    // Select events with two muons of opposite charge
    auto df_os = df_2mu.Filter("Muon_charge[0] != Muon_charge[1]", "Muons with opposite charge");

    // Compute invariant mass of the dimuon system
    auto df_rec = df_os.Define("Dimuon_mass", computeInvariantMass, {"Muon_pt", "Muon_eta", "Muon_phi", "Muon_mass"})
                        .Define("Dimuon_Pt", computePt, {"Muon_pt", "Muon_eta", "Muon_phi", "Muon_mass"})
                        .Define("Dimuon_Eta", computeEta, {"Muon_pt", "Muon_eta", "Muon_phi", "Muon_mass"})
                        .Define("Dimuon_Phi", computePhi, {"Muon_pt", "Muon_eta", "Muon_phi", "Muon_mass"});

    // Select events that result in inavriant mass of eta
    auto df_X = df_rec.Filter("Dimuon_mass > 75 && Dimuon_mass < 105", "X");

    // Create canvas for plotting
    gStyle->SetOptStat(0);
    gStyle->SetOptFit(1);
    gStyle->SetTextFont(42);
    auto c = new TCanvas("c", "", 800, 700);
    c->Divide(2,2);

    // Book histogram of dimuon mass spectrum
    auto low_pt = df_X.Min("Dimuon_Pt"); // Lower edge of the histogram
    auto up_pt = df_X.Max("Dimuon_Pt"); // Upper edge of the histogram
    auto bins_pt = ((*up_pt)-(*low_pt))*100; // Number of bins in the histogram
    auto hist_pt = df_X.Histo1D({"", "", int(bins_pt), *low_pt, *up_pt}, "Dimuon_Pt");

    auto low_eta = df_X.Min("Dimuon_Eta"); // Lower edge of the histogram
    auto up_eta = df_X.Max("Dimuon_Eta"); // Upper edge of the histogram
    auto bins_eta = ((*up_eta)-(*low_eta))*100; // Number of bins in the histogram
    auto hist_eta = df_X.Histo1D({"", "", int(bins_eta), *low_eta, *up_eta}, "Dimuon_Eta");

    auto low_phi = df_X.Min("Dimuon_Phi"); // Lower edge of the histogram
    auto up_phi = df_X.Max("Dimuon_Phi"); // Upper edge of the histogram
    auto bins_phi = ((*up_phi)-(*low_phi))*100; // Number of bins in the histogram
    auto hist_phi = df_X.Histo1D({"", "", int(bins_phi), *low_phi, *up_phi}, "Dimuon_Phi");

    // Draw histogram for Pt
    c->cd(1);
    c->cd(1)->SetLogx();
    c->cd(1)->SetLogy();
    hist_pt->GetXaxis()->SetMoreLogLabels(1);
    hist_pt->GetXaxis()->SetTitle("Pt_{#mu#mu} (GeV)");
    hist_pt->GetXaxis()->SetTitleSize(0.04);
    hist_pt->GetYaxis()->SetTitle("N_{Events}");
    hist_pt->GetYaxis()->SetTitleSize(0.04);
    hist_pt->DrawClone();

    c->cd(2);
    hist_eta->GetXaxis()->SetMoreLogLabels(1);
    hist_eta->GetXaxis()->SetTitle("#eta_{#mu#mu}");
    hist_eta->GetXaxis()->SetTitleSize(0.04);
    hist_eta->GetYaxis()->SetTitle("N_{Events}");
    hist_eta->GetYaxis()->SetTitleSize(0.04);
    hist_eta->DrawClone();

    c->cd(3);
    hist_phi->GetXaxis()->SetMoreLogLabels(1);
    hist_phi->GetXaxis()->SetTitle("#phi_{#mu#mu}");
    hist_phi->GetXaxis()->SetTitleSize(0.04);
    hist_phi->GetYaxis()->SetTitle("N_{Events}");
    hist_phi->GetYaxis()->SetTitleSize(0.04);
    hist_phi->DrawClone();    
}


int main() {
    dimuonSpectrum_pg();
}