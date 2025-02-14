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

    // Compute Pt, Eta, Phi and invariant mass of the dimuon system
    auto df_rec = df_os.Define("Dimuon_mass", computeInvariantMass, {"Muon_pt", "Muon_eta", "Muon_phi", "Muon_mass"});
    
    // Create new dataframes separating the values based on charge of the muons
    auto df_pos = df_rec.Define("P_Muon_Pt", "Muon_pt[Muon_charge == 1]")
                        .Define("P_Muon_Eta", "Muon_eta[Muon_charge == 1]")
                        .Define("P_Muon_Phi", "Muon_phi[Muon_charge == 1]");
    
    auto df_neg = df_rec.Define("N_Muon_Pt", "Muon_pt[Muon_charge == -1]")
                        .Define("N_Muon_Eta", "Muon_eta[Muon_charge == -1]")
                        .Define("N_Muon_Phi", "Muon_phi[Muon_charge == -1]");

    // Select events that result in inavriant mass of required particle
    auto df_X_pos = df_pos.Filter("Dimuon_mass > 75 && Dimuon_mass < 105");
    auto df_X_neg = df_neg.Filter("Dimuon_mass > 75 && Dimuon_mass < 105");

    // Create canvas for plotting
    gStyle->SetOptStat(0);
    gStyle->SetOptFit(1);
    gStyle->SetTextFont(42);
    auto c = new TCanvas("c", "", 800, 700);
    c->Divide(3,2);

    // Book histogram for positive muons
    auto low_p_pt = df_X_pos.Min("P_Muon_Pt"); // Lower edge of the histogram
    auto up_p_pt = df_X_pos.Max("P_Muon_Pt"); // Upper edge of the histogram
    auto bins_p_pt = ((*up_p_pt)-(*low_p_pt))*100; // Number of bins in the histogram
    auto hist_p_pt = df_X_pos.Histo1D({"", "", int(bins_p_pt), *low_p_pt, *up_p_pt}, "P_Muon_Pt");

    auto low_p_eta = df_X_pos.Min("P_Muon_Eta"); // Lower edge of the histogram
    auto up_p_eta = df_X_pos.Max("P_Muon_Eta"); // Upper edge of the histogram
    auto bins_p_eta = ((*up_p_eta)-(*low_p_eta))*100; // Number of bins in the histogram
    auto hist_p_eta = df_X_pos.Histo1D({"", "", int(bins_p_eta), *low_p_eta, *up_p_eta}, "P_Muon_Eta");

    auto low_p_phi = df_X_pos.Min("P_Muon_Phi"); // Lower edge of the histogram
    auto up_p_phi = df_X_pos.Max("P_Muon_Phi"); // Upper edge of the histogram
    auto bins_p_phi = ((*up_p_phi)-(*low_p_phi))*100; // Number of bins in the histogram
    auto hist_p_phi = df_X_pos.Histo1D({"", "", int(bins_p_phi), *low_p_phi, *up_p_phi}, "P_Muon_Phi");

    // Book histogram for negative muons
    auto low_n_pt = df_X_neg.Min("N_Muon_Pt"); // Lower edge of the histogram
    auto up_n_pt = df_X_neg.Max("N_Muon_Pt"); // Upper edge of the histogram
    auto bins_n_pt = ((*up_n_pt)-(*low_n_pt))*100; // Number of bins in the histogram
    auto hist_n_pt = df_X_neg.Histo1D({"", "", int(bins_n_pt), *low_n_pt, *up_n_pt}, "N_Muon_Pt");

    auto low_n_eta = df_X_neg.Min("N_Muon_Eta"); // Lower edge of the histogram
    auto up_n_eta = df_X_neg.Max("N_Muon_Eta"); // Upper edge of the histogram
    auto bins_n_eta = ((*up_n_eta)-(*low_n_eta))*100; // Number of bins in the histogram
    auto hist_n_eta = df_X_neg.Histo1D({"", "", int(bins_n_eta), *low_n_eta, *up_n_eta}, "N_Muon_Eta");

    auto low_n_phi = df_X_neg.Min("N_Muon_Phi"); // Lower edge of the histogram
    auto up_n_phi = df_X_neg.Max("N_Muon_Phi"); // Upper edge of the histogram
    auto bins_n_phi = ((*up_n_phi)-(*low_n_phi))*100; // Number of bins in the histogram
    auto hist_n_phi = df_X_neg.Histo1D({"", "", int(bins_n_phi), *low_n_phi, *up_n_phi}, "N_Muon_Phi");

    // Draw histogram for Pos muons
    c->cd(1);
    c->cd(1)->SetLogx();
    c->cd(1)->SetLogy();
    hist_p_pt->GetXaxis()->SetMoreLogLabels(1);
    hist_p_pt->GetXaxis()->SetTitle("Pt_{#mu^{+}} (GeV)");
    hist_p_pt->GetXaxis()->SetTitleSize(0.04);
    hist_p_pt->GetYaxis()->SetTitle("N_{Events}");
    hist_p_pt->GetYaxis()->SetTitleSize(0.04);
    hist_p_pt->DrawClone();

    c->cd(2);
    hist_p_eta->GetXaxis()->SetMoreLogLabels(1);
    hist_p_eta->GetXaxis()->SetTitle("#eta_{#mu^{+}}");
    hist_p_eta->GetXaxis()->SetTitleSize(0.04);
    hist_p_eta->GetYaxis()->SetTitle("N_{Events}");
    hist_p_eta->GetYaxis()->SetTitleSize(0.04);
    hist_p_eta->DrawClone();

    c->cd(3);
    hist_p_phi->GetXaxis()->SetMoreLogLabels(1);
    hist_p_phi->GetXaxis()->SetTitle("#phi_{#mu^{+}}");
    hist_p_phi->GetXaxis()->SetTitleSize(0.04);
    hist_p_phi->GetYaxis()->SetTitle("N_{Events}");
    hist_p_phi->GetYaxis()->SetTitleSize(0.04);
    hist_p_phi->DrawClone();    

    // Draw histogram for Neg muons
    c->cd(4);
    c->cd(4)->SetLogx();
    c->cd(4)->SetLogy();
    hist_n_pt->GetXaxis()->SetMoreLogLabels(1);
    hist_n_pt->GetXaxis()->SetTitle("Pt_{#mu^{-}} (GeV)");
    hist_n_pt->GetXaxis()->SetTitleSize(0.04);
    hist_n_pt->GetYaxis()->SetTitle("N_{Events}");
    hist_n_pt->GetYaxis()->SetTitleSize(0.04);
    hist_n_pt->DrawClone();

    c->cd(5);
    hist_n_eta->GetXaxis()->SetMoreLogLabels(1);
    hist_n_eta->GetXaxis()->SetTitle("#eta_{#mu^{-}}");
    hist_n_eta->GetXaxis()->SetTitleSize(0.04);
    hist_n_eta->GetYaxis()->SetTitle("N_{Events}");
    hist_n_eta->GetYaxis()->SetTitleSize(0.04);
    hist_n_eta->DrawClone();

    c->cd(6);
    hist_n_phi->GetXaxis()->SetMoreLogLabels(1);
    hist_n_phi->GetXaxis()->SetTitle("#phi_{#mu^{-}}");
    hist_n_phi->GetXaxis()->SetTitleSize(0.04);
    hist_n_phi->GetYaxis()->SetTitle("N_{Events}");
    hist_n_phi->GetYaxis()->SetTitleSize(0.04);
    hist_n_phi->DrawClone();    
}


int main() {
    dimuonSpectrum_pg();
}